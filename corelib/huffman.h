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
  huffman_code();
  void add_left();
  void add_right();
  unsigned get_code() const;
  unsigned get_size() const;
  void set_code(unsigned);
  void set_size(unsigned);
};
std::ostream &operator<<(std::ostream &os, const huffman_code &m); //for debug purpose only

unsigned *count_frequency(input_param);
tree *make_huffman_tree(input_param);
huffman_code *generate_code(tree *);
int encode_file(huffman_code *, input_param);
int output_table(input_param);
int output_code(input_param);

huffman_code *reconstruct_code_from_ascii();
void naive_decode(huffman_code *, input_param);

#endif