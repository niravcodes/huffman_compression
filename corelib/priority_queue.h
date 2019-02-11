#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "tree.h"
class priority_queue
{
  private:
  public:
    bool is_empty();
    void enqueue(tree::leaf);
    tree::leaf dequeue();
};
#endif
