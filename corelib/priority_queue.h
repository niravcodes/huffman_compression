#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "tree.h"
class priority_queue
{
private:
  tree::node *alphabets;
  unsigned char top;

public:
  priority_queue();
  ~priority_queue();
  bool is_empty();
  void enqueue(tree::node &);
  tree::node dequeue();
};
#endif
