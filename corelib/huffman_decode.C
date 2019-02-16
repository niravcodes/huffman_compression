#include "huffman.h"
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
    unsigned code;
    unsigned file_size_in_bits = huff_code[257].get_code();
    ifstream in;
    ofstream out;
    in.open(options.input_file, ios::binary | ios::in);
    out.open(options.output_file, ios::binary | ios::out);
    for (unsigned long i = 0; i < options.input_file_size; i++)
    {
        in >> buffer;
        for (int j = 0; j < 8; j++)
        {
            code = (code << 1) | pluck_bit(buffer);
            for (int k = 0; k < 256; k++)
            {
                if (code == huff_code[i].get_code())
                {
                    out << (unsigned char)k;
                    code = 0;
                }
            }
            buffer = buffer << 1;

            if (file_size_in_bits--)
                break;
        }
    }
    delete[] huff_code;
    in.close();
    out.close();
}