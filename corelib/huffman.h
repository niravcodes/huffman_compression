#ifndef _HUFFMAN_H
#define _HUFFMAN_H
#include "../param_parser.h"
#include "tree.h"

tree *make_huffman_tree(input_param);
unsigned *generate_code(tree *);

#endif