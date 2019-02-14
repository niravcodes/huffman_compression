#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include "../param_parser.h"
#include "tree.h"

class huffman_code
{
  private:
    unsigned code;
    unsigned size;

  public:
    struct hcode
    {
        unsigned code;
        unsigned size;
    };
    huffman_code();
    void add_left();
    void add_right();
    hcode get_code();
};

tree *make_huffman_tree(input_param);
unsigned *generate_code(tree *);

#endif