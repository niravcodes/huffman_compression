#include "priority_queue.h"

priority_queue::priority_queue()
{
    alphabets = new tree::node[256];
    top = 0;
}
priority_queue::~priority_queue()
{
    delete[] alphabets;
}
void priority_queue::enqueue(tree::node &lf)
{
    alphabets[top++] = lf;
}
tree::node priority_queue::dequeue()
{
    if (is_empty())
        return tree::node(); //return empty node if nothing
    if (top == 1)
        return alphabets[--top];

    unsigned index = 0;
    tree::node smallest = alphabets[index];
    for (int i = 0; i < top; i++)
    {
        if (alphabets[i] < smallest)
        {
            smallest = alphabets[i];
            index = i;
        }
    }
    alphabets[index] = alphabets[--top];
    return smallest;
}
bool priority_queue::is_empty()
{
    return !top;
}
unsigned priority_queue::element_count()
{
    return top;
}

bool queue::is_empty()
{
    return !(bottom > top);
}
queue::queue()
{
    priority_queue();
    bottom = 0;
}
void queue::enqueue(tree::node &a)
{
    alphabets[bottom++] = a;
    if (bottom >= QUEUE_MAXSIZE)
        bottom = 0;
}
tree::node queue::dequeue()
{
    if (is_empty())
        return tree::node();

    if (top >= (QUEUE_MAXSIZE - 1))
    {
        top = 0;
        return alphabets[QUEUE_MAXSIZE - 1];
    }
    return alphabets[top++];
}