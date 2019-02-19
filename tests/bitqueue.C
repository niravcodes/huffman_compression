#include <iostream>
#include <fstream>
#include "../debughelpers/bit_printer.h"

#include "../corelib/bitqueue.h"
using namespace std;

int main()
{
    unsigned char *data = new unsigned char[20];
    ifstream in;
    in.open("tests/priority_queue.C", ios::binary | ios::in);

    in.read((char *)data, 20);

    bitqueue test(20, data);

    cout << print_bits(test.peek(6), 32) << endl;
    if (test.forward(8))
        cout << "done" << endl;
    cout << print_bits(test.peek(15), 32) << endl;
}