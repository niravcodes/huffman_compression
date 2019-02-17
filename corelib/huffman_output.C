#include "huffman.h"

//for debug
#include "../debughelpers/bit_printer.h"
#include <iostream>
using namespace std;

//TODO: There is lot of code duplication here (plus same things are being done many times)
//TODO: Eg: frequencies are calculated everytime they're needed.
//TODO: Radically reorganise the code to not rely on input_param
//TODO: and instead pass streams and data around.
int output_table(input_param options)
{
    tree *huffman_tree = make_huffman_tree(options);
    huffman_code *huff_code = generate_code(huffman_tree);

    unsigned long file_size = 0;
    unsigned *count = count_frequency(options);

    cout << "Byte\t\t\tCode\t\t\tSize\t\t\tFrequency" << endl;
    for (int i = 0; i < 256; i++)
    {
        if (count[i])
        {
            cout << hex << i << "\t\t\t";
            cout << print_bits(huff_code[i].get_code(), 16) << "\t\t\t";
            cout << huff_code[i].get_size() << "\t\t\t";
            cout << count[i] << endl;
            file_size += count[i] * huff_code[i].get_size(); //frequency * code size
        }
    }
    cout << "Resulting size in bits: " << file_size << endl;
    cout << "Resulting size in bytes: " << file_size / 8 << endl;
    cout << "Resulting size in MB: " << file_size / (8 * 1024 * 1024) << "MB" << endl;

    delete[] count;
    delete huffman_tree;
    delete huff_code;
    return 0;
}

int output_code(input_param options) //eventually we'll serialize code to the file. but for now, lets follow UNIX philosophy
{
    tree *huffman_tree = make_huffman_tree(options);
    huffman_code *huff_code = generate_code(huffman_tree);

    unsigned long file_size = 0;
    unsigned *count = count_frequency(options);

    for (int i = 0; i < 256; i++)
    {
        cout << huff_code[i].get_code() << " ";
        cout << huff_code[i].get_size() << " " << endl;
        file_size += count[i] * huff_code[i].get_size(); //frequency * code size
    }
    cout << "---" << endl;
    cout << file_size << endl;

    delete[] count;
    delete huffman_tree;
    delete huff_code;
    return 0;
}