#include "priority_queue.h"

priority_queue::priority_queue()
{
    alphabets = new tree::leaf[256];
    top = 0;
}
void priority_queue::enqueue(tree::leaf &lf)
{
    if (top == 255)
        return;
    alphabets[top++] = lf;
}
tree::leaf priority_queue::dequeue()
{
    unsigned char index = 0;
    tree::leaf greatest = alphabets[index];
    for (int i = 0; i < top; i++)
    {
        if (greatest < alphabets[i])
        {
            greatest = alphabets[i];
            index = i;
        }
    }
    alphabets[index] = alphabets[--top];
}
bool priority_queue::is_empty()
{
    return !top;
}