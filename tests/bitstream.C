#include "../corelib/bitstream.h"
#include "../debughelpers/bit_printer.h"
#include <iostream>
using namespace std;

int main()
{
    bitstream a(4);
    const int bit_size = 4 * 8;
    cout << "testing" << endl;
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0x55, 15);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 5);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xaa, 10);

    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xffe, 12);
    cout << "time for reaminder" << endl;
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;

    a.reset_buffer();
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
}
