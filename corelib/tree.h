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

  public:
    node();
    node(unsigned char, unsigned,
         node *left, node *right);
    node(const node &m);
    void delete_subtree();
    // ~node();
    node &operator=(const node &m);
    bool operator<(const node &b);
    bool add_left(node *);
    bool add_right(node *);
    bool add_leaves(node *, node *);
    node *get_left() const;
    node *get_right() const;
    bool is_leaf() const;
    unsigned char get_data() const;
    unsigned get_frequency() const;
  };

  tree();
  tree(node *);
  ~tree();
  node *get_root();

private:
  node *root;
};

std::ostream &operator<<(std::ostream &os, const tree::node &m); //for debug purpose only
#endif