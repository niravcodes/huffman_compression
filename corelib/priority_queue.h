#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H
#include "tree.h"

#define QUEUE_MAXSIZE 256

template <class T>
class priority_queue
{
protected:
  T *alphabets;
  unsigned top;

public:
  priority_queue();
  ~priority_queue();
  bool is_empty();
  void enqueue(T &);
  unsigned element_count();
  T dequeue();
};

template <class T>
class queue : public priority_queue<T>
{
protected:
  unsigned bottom;

public:
  queue();
  bool is_empty();
  T dequeue();
  void enqueue(T &);
};
#include "priority_queue.T"
#endif
