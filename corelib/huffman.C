#include <iostream> //for debug only
#include <fstream>

#include "huffman.h"
#include "tree.h"
#include "priority_queue.h"

using namespace std;

unsigned *count_frequency(ifstream &in, unsigned file_size)
{
    char byte;
    unsigned *count = new unsigned[256];
    for (int i = 0; i < 256; i++)
        count[i] = 0;

    for (int i = 0; i < file_size; ++i)
    {
        in >> byte;
        count[(unsigned char)byte]++;
    }
    return count;
}
priority_queue *generate_alphabets(unsigned *count)
{
    priority_queue *q = new priority_queue;
    for (int i = 0; i < 256; i++)
    {
        tree::node x(i, count[i], NULL, NULL);
        q->enqueue(x);
    }
    return q;
}
tree *make_huffman_tree(input_param options)
{
    //open the file for inspection
    ifstream in_file;
    in_file.open(options.input_file, ios::binary | ios::in);

    unsigned *count = count_frequency(in_file, options.input_file_size);
    priority_queue *x = generate_alphabets(count);

    int cnt = 0;
    while (x->element_count() > 1)
    {
        tree::node b1 = x->dequeue();
        tree::node b2 = x->dequeue();
        tree::node *a = new tree::node(b1);
        tree::node *b = new tree::node(b2);
        tree::node c(0, a->get_frequency() + b->get_frequency(), a, b);
        x->enqueue(c);
    }

    tree::node temp = x->dequeue();
    tree::node temp2 = temp;
    tree::node *root = new tree::node(temp);
    tree *huffman_tree = new tree(root);

    in_file.close();

    return huffman_tree;
}