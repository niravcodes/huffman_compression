#include "bitstream.h"
bitstream::bitstream()
{
    bitstream(DEFAULT_BUFFER_SIZE);
}
bitstream::bitstream(unsigned buffersize)
{
    buffer = new unsigned char[buffersize];
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
unsigned bitstream::get_free_bits()
{
    return (buffer_size * 8) - bit_pos;
}
int bitstream::micropack(unsigned char data, unsigned size)
{
    if (get_free_bits() >= size)
    {
    }
}

int bitstream::pack(unsigned data, unsigned bit_l)
{
    if (bit_l > 32)
        return 1;

    unsigned char data_local;
    if (bit_l <= 8)
    {
        data_local = 0xff & data;
        data_local = data_local << (8 - bit_l);
    }
}