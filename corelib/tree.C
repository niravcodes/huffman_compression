#include "tree.h"
#include <ostream>

tree::node::node()
{
  node(0, 0, _NULL, _NULL);
}
tree::node::node(unsigned char data, unsigned frequency, tree::node *left = _NULL, tree::node *right = _NULL)
{
  this->data = data;
  this->frequency = frequency;
  add_leaves(left, right);
}
tree::node::node(const tree::node &m)
{
  data = m.data;
  frequency = m.frequency;
  add_leaves(m.get_left(), m.get_right());
}
tree::node &tree::node::operator=(const tree::node &m)
{
  data = m.data;
  frequency = m.frequency;
  add_leaves(m.get_left(), m.get_right());
  return *this;
}
bool tree::node::add_leaves(tree::node *lf, tree::node *rg)
{
  left = lf;
  right = rg;
}
bool tree::node::is_leaf() const
{
  if (left == _NULL and right == _NULL)
    return true;
  return false;
}
bool tree::node::operator<(const tree::node &b)
{
  if (frequency < b.frequency)
    return true;
  return false;
}
unsigned char tree::node::get_data() const
{
  return data;
}
unsigned tree::node::get_frequency() const
{
  return frequency;
}
std::ostream &operator<<(std::ostream &os, const tree::node &m)
{
  char a = m.is_leaf() ? '*' : '-';
  return os << (unsigned)m.get_data() << "\t\t" << m.get_frequency() << a;
}
tree::node *tree::node::get_right() const
{
  return right;
}
tree::node *tree::node::get_left() const
{
  return left;
}
tree::tree()
{
  root = _NULL;
}
tree::tree(tree::node *r)
{
  root = r;
}
tree::node *tree::get_root()
{
  return root;
}