#include "bitqueue.h"
#include <iostream>
using namespace std;

bitqueue::bitqueue(unsigned size, byte *data)
{
    buffer_size = size;
    buffer = data;
    top = 0;
    bottom = size * 8; //in bits
    backup = 0;
}

bitqueue::~bitqueue()
{
    delete[] buffer;
}

inline unsigned long bitqueue::get_bit_offset()
{
    return (7 - top % 8);
}
inline unsigned long bitqueue::get_byte_pos()
{
    return top / 8;
}
inline unsigned long bitqueue::get_end_byte()
{
    return (bottom / 8);
}
unsigned bitqueue::get_four_or_less_bytes()
{
    int remaining_bytes = get_end_byte() - get_byte_pos();
    if (remaining_bytes > 4)
        remaining_bytes = 4;

    unsigned ret = 0;
    for (int i = 0; i < remaining_bytes; i++)
    {
        ret = ret << 8 | buffer[get_byte_pos() + i];
    }
    return ret;
}

unsigned bitqueue::peek(unsigned length)
{
    if ((bottom - top) >= length)
    {
        return get_four_or_less_bytes() & ~((long)0xffffffff >> length);
    }
    else
    {
        //There is really nothing that can be done at this point.
        //For some reason, forward() was not called after peek.
        return ~0;
    }
}

int bitqueue::forward(unsigned length)
{
    if (bottom - top >= length)
    {
        top += length;
        return 1;
    }
    else
    {
        //prepare for a refill function
        backup = get_four_or_less_bytes();
        return 0;
    }
}

void bitqueue::refill(byte *data, unsigned size)
{
    delete[] buffer;
    buffer = data;
    buffer_size = size;
    backup = 0;
}