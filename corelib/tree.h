#ifndef _TREE_H
#define _TREE_H
#include <ostream>
#define _NULL 0

class tree
{
public:
  class node
  {
  private:
    unsigned char data;
    unsigned frequency;
    node *left;
    node *right;
    bool null; // Null is the mechanism to invalidate a leaf

  public:
    node();
    node(unsigned char, unsigned, node *left, node *right);
    bool operator<(const node &b);
    bool add_left(node *);
    bool add_right(node *);
    unsigned char get_data() const;
    unsigned get_frequency() const;
    bool is_null();
    void make_null();
  };

  tree();
  tree(node *);

private:
  node *root;
};

std::ostream &operator<<(std::ostream &os, const tree::node &m); //for debug purpose only
#endif