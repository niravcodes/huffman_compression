#include "huffman.h"
#include "../debughelpers/bit_printer.h"
#include "../param_parser.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
huffman_code *reconstruct_code_from_ascii()
{
    huffman_code *huff_code = new huffman_code[257];

    unsigned code, size;
    for (int i = 0; i < 256; i++)
    {

        cin >> code >> size;
        cout << code << " " << size << endl;
        huff_code[i].set_code(code);
        huff_code[i].set_size(size);
    }

    string x;
    cin >> x;
    cout << x << endl;
    cin >> code;
    cout << code << "file size in bits" << endl;
    huff_code[256].set_code(code); //no this no not code, this is the size of file in bits
    return huff_code;
}

inline bool pluck_bit(unsigned char buffer)
//this could be a marco function
//or a separate class. IDK what to do
{
    return (buffer & 0x80);
}
inline unsigned pack_bit(unsigned code, bool bit)
{
    return (code << 1) | bit;
}

void naive_decode(huffman_code *huff_code, input_param options)
{
    unsigned char buffer;
    unsigned code = 0;
    unsigned code_size = 0;
    unsigned file_size_in_bits = huff_code[256].get_code() - 1;
    ifstream in;
    ofstream out;
    in.open(options.input_file, ios::binary | ios::in);
    out.open(options.output_file, ios::binary | ios::out);
    cout << "in naive_decode" << endl;

    for (unsigned long i = 0; i < options.input_file_size; i++)
    {
        buffer = in.get();
        for (int j = 0; j < 8; j++)
        {
            code = (code << 1) | pluck_bit(buffer);
            code_size++;
            buffer = buffer << 1;
            cout << "code : " << print_bits(code, 32) << endl;
            cout << "buffer: " << print_bits(buffer, 8) << endl;

            for (int k = 0; k < 256; k++)
            {
                cout << code << " " << code_size << "     " << huff_code[k].get_code() << "   " << huff_code[k].get_size() << endl;
                if (code == huff_code[k].get_code() && code_size == huff_code[k].get_size())
                {
                    cout << "MATCH" << endl;
                    out << (unsigned char)k;
                    code = 0;
                    code_size = 0;
                    break;
                }
            }
            cout << endl;

            if (!file_size_in_bits--)
                break;
        }
        // if (i % 1024)
        // {
        //     cout << i << "kb" << "\n";
        // }
    }
    delete[] huff_code;
    in.close();
    out.close();
}