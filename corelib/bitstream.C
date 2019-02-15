#include "bitstream.h"
bitstream::bitstream()
{
    bitstream(DEFAULT_BUFFER_SIZE);
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
    if (!remainder_size) //if remainder doesn't already exist
    {
        remainder_size = size;
        remainder = data & ~(0xffu << (size));
        return true;
    }
    return false;
}
int bitstream::micropack(byte data, unsigned size)
{
    if (get_free_bits() >= size)
    {
        data = data << (8 - size);                //move data so MSB is at 8th pos
        byte buff = buffer[get_byte_pos()];       //copy last byte of buffer to modify
        buff = buff | (data >> get_bit_offset()); //pack input data's portion into buffer
        data = data << (8 - get_bit_offset());    //pack the rest of data on the next byte

        buffer[get_byte_pos()] = buff;     //flush the change
        buffer[get_byte_pos() + 1] = data; //flush the change
        bit_pos += size;
        return 0; //no problems, sire.
    }
    else
    {
        unsigned r_size = size - get_free_bits();
        micropack(data >> (r_size), get_free_bits()); //micropack whatever fits
        bit_pos += get_free_bits();
        add_remainder(data, r_size);
        return r_size;
    }
}

int bitstream::pack(unsigned data, unsigned bit_l)
{
    if (bit_l > 32)
        return -1;
    else if (bit_l <= 8)
        return micropack(data, bit_l);
    else
    { //time to chop unsigned to bytes
        byte buff;
        for (int i = 0; i < 4; i++)
        {
            data = data >> (8 * i);
            buff = (byte)data;
            if (micropack(buff, bit_l - (8 * i)) >= 0) //if buffer has filled up
            {
            }
        }
    }
}