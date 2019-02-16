#include "../corelib/bitstream.h"
#include "../debughelpers/bit_printer.h"
#include <iostream>
using namespace std;

int main()
{
    bitstream a(8);
    const int bit_size = 8 * 8;
    cout << "testing" << endl;
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0x55, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 6);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xaa, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0x00, 2);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xff, 8);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.pack(0xaaaa, 32);
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
    a.reset_buffer();
    cout << print_bit_array(a.flush_buffer(), bit_size) << endl;
}
