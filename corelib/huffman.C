#include <iostream> //for debug only
#include <fstream>

#include "huffman.h"
#include "tree.h"
#include "priority_queue.h"

using namespace std;

unsigned debug_count = 0;

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
        debug_count += count[i];
        tree::node x(i, count[i], NULL, NULL);
        cout << x << "^" << endl;
        q->enqueue(x);
    }
    return q;
}
void huffman(input_param options)
{
    //open the file for inspection
    ifstream in_file;
    in_file.open(options.input_file, ios::binary | ios::in);

    unsigned *count = count_frequency(in_file, options.input_file_size);
    priority_queue *x = generate_alphabets(count);

    int cnt = 0;
    cout << "----------start log printing------------" << endl;
    while (x->element_count() > 1)
    {
        tree::node b1 = x->dequeue();
        tree::node b2 = x->dequeue();
        cout << b1 << "\t\t" << endl
             << b2 << endl
             << endl;
        tree::node *a = new tree::node(b1.get_data(), b1.get_frequency(), b1.get_left(), b1.get_right()); //todo:copy constructor
        tree::node *b = new tree::node(b2.get_data(), b2.get_frequency(), b2.get_left(), b2.get_right()); //todo:copy constructor
        tree::node c(0, a->get_frequency() + b->get_frequency(), a, b);
        x->enqueue(c);
    }
    cout << "-----------stop log printing------------" << endl;
    cout << x->element_count() << ":elements in pq" << endl;
    cout << x->dequeue() << endl;
    cout << debug_count << endl; //for debug only

    in_file.close();
}