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
