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
        int return_size = 0;
        unsigned no_of_bytes = bit_l / 8;
        unsigned unaligned_bits = bit_l % 8;
        byte buff[4] = {0, 0, 0, 0};

        for (unsigned i = 0; i < 4; i++)
        {
            data = data >> (i * 8);
            buff[i] = (byte)data;
        }

        int overflow = micropack(buff[no_of_bytes], unaligned_bits); // first push the MSB side
        if (overflow > 0)
        {
            //didn't fit. Needs to be repacked
            return_size = bit_l - overflow;
            // add_remainder(buff[no_of_bytes--] >> (unaligned_bits - overflow), overflow);
            for (int i = 0; i < no_of_bytes; i++)
            {
                add_remainder(buff[no_of_bytes--], 8);
            }
            return return_size;
        }
        else
        {
            no_of_bytes--;

            while (no_of_bytes)
            {
                overflow = micropack(buff[no_of_bytes--], 8);
                if (overflow >= 0)
                {
                    return_size -= (8 * i - overflow);
                }
            }
        }
    }
}