#include "bitstream.h"
//debug headers
#include <iostream>
#include "../debughelpers/bit_printer.h"

bitstream::bitstream()
{
    bitstream(DEFAULT_BUFFER_SIZE);
    /* 
    why does calling this function not set the buffer_size??? 
    TODO: Investigate
    */
}
bitstream::bitstream(unsigned buffersize)
{
    buffer = new byte[buffersize];
    for (unsigned i = 0; i < buffersize; i++)
        buffer[i] = 0;
    buffer_size = buffersize;
    bit_pos = 0;
    remainder = 0;
    remainder_size = 0;
}
bitstream::~bitstream()
{
    delete buffer;
}
const byte *bitstream::flush_buffer()
{
    return buffer;
}
inline unsigned bitstream::get_byte_pos()
{
    return bit_pos / 8;
}
inline unsigned bitstream::get_free_bits()
{
    return (buffer_size * 8) - bit_pos;
}
inline unsigned bitstream::get_bit_offset()
{
    return bit_pos % 8;
}
bool bitstream::add_remainder(unsigned data, unsigned size)
{
    //notice no checks. Yea, I don't care if remainder overflows
    //because EVERY pack() has to if if(pack() > 0)d and flushed
    //then reset.
    //At least for now, that is. maybe I can code a lock mechanism
    //in place later
    remainder_size += size;
    remainder = (remainder << size) | data & ~(0xffu << (size));
    return true;
}
int bitstream::micropack(byte data, unsigned size)
{
    if (!size)
        return 0; //needed for adding remainders w/pack(,)

    if (get_free_bits() >= size)
    {
        std::cout << "micropack : " << print_bits(data, 8) << "  " << size << std::endl;
        std::cout << "byte: " << get_byte_pos() << " bitoffset: " << get_bit_offset() << endl;

        byte buff = buffer[get_byte_pos()];       //copy last byte of buffer to modify
        data = data << (8 - size);                //move data so MSB is at 8th pos
        buff = buff | (data >> get_bit_offset()); //pack input data's portion into buffer
        data = data << (8 - get_bit_offset());    //pack the rest of data on the next byte

        buffer[get_byte_pos()] = buff;     //flush the change
        buffer[get_byte_pos() + 1] = data; //flush the change
        bit_pos += size;
        return 0; //no problems, sire.
    }
    else
    {
        std::cout << "needs to be put in remainder" << endl;
        unsigned r_size = size - get_free_bits();
        micropack(data >> (r_size), get_free_bits()); //micropack whatever fits
        bit_pos += get_free_bits();
        add_remainder(data, r_size);
        std::cout << "remainder: " << print_bits(remainder, 32) << "  " << remainder_size << std::endl;
        return r_size;
    }
}

bool bitstream::pack(unsigned data, unsigned bit_l)
{
    if (bit_l > 32)
        return false;
    else
    { //time to chop unsigned to bytes
        int return_size = 0;
        unsigned no_of_bytes = bit_l / 8;
        unsigned unaligned_bits = bit_l % 8;
        byte buff[4] = {0, 0, 0, 0};

        for (unsigned i = 0; i < 4; i++)
        {
            data = data >> (i * 8);
            buff[i] = (byte)data;
        }

        micropack(buff[no_of_bytes], unaligned_bits); // first push the MSB side
        while (no_of_bytes)
        {
            micropack(buff[--no_of_bytes], 8);
        }
    }

    if (remainder_size)
        return false;
    return true;
}
int bitstream::reset_buffer()
{
    for (int i = 0; i < buffer_size; i++) //This is not necessary, but it helps me debug.
    {
        buffer[i] = 0;
    }
    bit_pos = 0;
    pack(remainder, remainder_size);
    remainder = 0;
    remainder_size = 0;
    return true;
}