#include <iostream> //for debug only
#include <fstream>

#include "param_parser.h"
#include "huffman.h"

using namespace std;

void huffman(input_param options)
{
    //open the file for inspection
    ifstream in_file;
    in_file.open(options.input_file, ios::binary | ios::in);

    char byte;
    unsigned count[256];
    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; i < options.input_file_size; ++i)
    {
        in_file >> byte;
        count[(unsigned char)byte]++;
    }

    unsigned total = 0;
    for (int i = 0; i < 256; i++)
    {
        total += count[i];
        cout << i << " : " << count[i] << endl;
    }
    for (int i = 0; i < 256; i++)
        cout << i << " : " << ((double)count[i] / total) << endl;
}