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
    if (top == 255)
        return;
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