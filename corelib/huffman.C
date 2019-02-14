#include <iostream> //for debug only
#include <fstream>

#include "huffman.h"
#include "tree.h"
#include "priority_queue.h"

using namespace std;

huffman_code::huffman_code()
{
    code = 0;
    size = 0;
}
void huffman_code::add_left()
{
    code = code << 1;
    size++;
}
void huffman_code::add_right()
{
    code = code << 1 | 1;
    size++;
}
unsigned huffman_code::get_code() const
{
    return code;
}
unsigned huffman_code::get_size() const
{
    return size;
}
std::ostream &operator<<(std::ostream &os, const huffman_code &m)
{
    return os << (unsigned)m.get_code() << "\t\t" << m.get_size();
}

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
priority_queue<tree::node> *generate_alphabets(unsigned *count)
{
    priority_queue<tree::node> *q = new priority_queue<tree::node>;
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
    priority_queue<tree::node> *x = generate_alphabets(count);
    delete[] count;

    int cnt = 0;
    tree::node *a, *b, element, c;
    while (x->element_count() > 1)
    {
        element = x->dequeue();
        a = new tree::node(element);
        element = x->dequeue();
        b = new tree::node(element);
        c = tree::node(0, a->get_frequency() + b->get_frequency(), a, b);
        x->enqueue(c);
    }

    //there is only one element in the priority queue now: The root.
    element = x->dequeue();
    tree::node *root = new tree::node(element);
    tree *huffman_tree = new tree(root);

    in_file.close();
    return huffman_tree;
}

//the idea is to keep on following left-ward nodes while putting the right-ward nodes
//in a queue (why not stack? cuz i alread had half a queue)
//once the leftmost leaf is reached, add it to the code-table
//then access the queue. Anytime a queue is consulted, a 1 is added to the code bit pattern
//convention : left is 0;
huffman_code *generate_code(tree *t)
{
    huffman_code *code = new huffman_code[256];

    tree::node *current = t->get_root();
    huffman_code current_huff_code;
    tree::node temp_node;

    queue<tree::node> q;
    queue<huffman_code> hq;

    while (1)
    {
        if (current->is_leaf())
        {
            code[current->get_data()] = current_huff_code;
            if (q.is_empty())
            {
                break;
            }
            else
            {
                temp_node = q.dequeue();
                current = &temp_node;
                current_huff_code = hq.dequeue();
                current_huff_code.add_right();
            }
        }
        else
        {
            q.enqueue(*current->get_right());
            hq.enqueue(current_huff_code);
            current = current->get_left();
            current_huff_code.add_left();
        }
    }
    return code;
}