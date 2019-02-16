#include "huffman.h"
#include <iostream>

huffman_code *reconstruct_code_from_ascii()
{
    using namespace std;
    huffman_code *huff_code = new huffman_code[256];
    for (int i = 0; i < 256; i++)
    {
        unsigned code, size;
        cin >> code >> size;
        huff_code[i].set_code(code);
        huff_code[i].set_size(size);
    }
    return huff_code;
}
