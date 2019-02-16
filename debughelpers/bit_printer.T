#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void print_bits(T a)
{
    bool bit;
    string bitpattern = "";
    for (int i = 0; i < sizeof(T) * 8; i++)
    {
        bit = a & 1;
        if (bit)
            bitpattern = "1" + bitpattern;
        else
            bitpattern = "0" + bitpattern;
        a = a >> 1;
    }
    cout << setfill(' ') << setw(16) << bitpattern;
}

template <class T>
string print_bits(T a, int size)
{
    bool bit;
    string bitpattern = "";
    for (int i = 0; i < size; i++)
    {
        bit = a & 1;
        if (bit)
            bitpattern = "1" + bitpattern;
        else
            bitpattern = "0" + bitpattern;
        a = a >> 1;
    }
    return bitpattern;
}

template <class T>
string print_bit_array(T a, int size)
{
    bool bit;
    string bitpattern = "";
    unsigned char bye;
    for (int i = 0; i < size / 8; i++)
    {
        bye = a[i];
        for (int j = 0; j < 8; j++)
        {
            bit = bye & 0x80;
            if (bit)
                bitpattern = bitpattern + "1";
            else
                bitpattern = bitpattern + "0";
            bye = bye << 1;
        }
        bitpattern += " ";
    }
    return bitpattern;
}
