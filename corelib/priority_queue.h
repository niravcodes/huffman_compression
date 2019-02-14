#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "tree.h"

#define QUEUE_MAXSIZE 256
class priority_queue
{
protected:
  tree::node *alphabets;
  unsigned top;

public:
  priority_queue();
  ~priority_queue();
  bool is_empty();
  void enqueue(tree::node &);
  unsigned element_count();
  tree::node dequeue();
};
class queue : public priority_queue
{
protected:
  unsigned bottom;

public:
  queue();
  bool is_empty();
  tree::node dequeue();
  void enqueue(tree::node &);
};
#endif
