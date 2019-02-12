#include "tree.h"

tree::leaf::leaf()
{
  leaf(0, 0, 0, 0);
}
tree::leaf::leaf(unsigned char data, unsigned frequency, tree::leaf *left = _NULL, tree::leaf *right = _NULL)
{
  this->data = data;
  this->frequency = frequency;
  tree::leaf::add_left(left);
  tree::leaf::add_right(right);
}
bool tree::leaf::add_left(tree::leaf *lf)
{
  left = lf;
}
bool tree::leaf::add_right(tree::leaf *lf)
{
  right = lf;
}
bool tree::leaf::operator<(const tree::leaf &b)
{
  if (frequency < b.frequency)
    return true;
  return false;
}
unsigned char tree::leaf::get_data()
{
  return data;
}
unsigned tree::leaf::get_frequency()
{
  return frequency;
}

tree::tree()
{
  root = _NULL;
}
tree::tree(tree::leaf *r)
{
  root = r;
}