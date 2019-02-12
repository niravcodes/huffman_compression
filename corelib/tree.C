#include "tree.h"
#include <ostream>

tree::node::node()
{
  node(0, 0, _NULL, _NULL);
  null = true;
}
bool tree::node::is_null()
{
  return null;
}
void tree::node::make_null()
{
  null = true;
}
tree::node::node(unsigned char data, unsigned frequency, tree::node *left = _NULL, tree::node *right = _NULL)
{
  this->data = data;
  this->frequency = frequency;
  tree::node::add_left(left);
  tree::node::add_right(right);
  null = false;
}
bool tree::node::add_left(tree::node *lf)
{
  if (is_null())
    return false;
  left = lf;
  return true;
}
bool tree::node::add_right(tree::node *lf)
{
  if (is_null())
    return false;
  right = lf;
  return true;
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
  return os << (unsigned)m.get_data() << "\t\t" << m.get_frequency();
}

tree::tree()
{
  root = _NULL;
}
tree::tree(tree::node *r)
{
  root = r;
}