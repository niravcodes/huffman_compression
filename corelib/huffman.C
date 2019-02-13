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
    //    cout << q->element_count() << ":elements in pq" << endl;
    return q;
}
tree *huffman(input_param options)
{
    //open the file for inspection
    ifstream in_file;
    in_file.open(options.input_file, ios::binary | ios::in);

    unsigned *count = count_frequency(in_file, options.input_file_size);
    priority_queue *x = generate_alphabets(count);

    int cnt = 0;
    //cout << x->element_count() << ":elements in pq" << endl;
    //cout << "----------start log printing------------" << endl;
    while (x->element_count() > 1)
    {
        tree::node b1 = x->dequeue();
        tree::node b2 = x->dequeue();
        //   cout << b1 << "\t\t" << endl
        //       << b2 << endl
        //      << endl;
        tree::node *a = new tree::node(b1.get_data(), b1.get_frequency(), b1.get_left(), b1.get_right()); //todo:copy constructor
        tree::node *b = new tree::node(b2.get_data(), b2.get_frequency(), b2.get_left(), b2.get_right()); //todo:copy constructor
        tree::node c(0, a->get_frequency() + b->get_frequency(), a, b);
        x->enqueue(c);
    }
    /*
    cout << "-----------stop log printing------------" << endl;
    cout << x->element_count() << ":elements in pq" << endl;
    */

    //i really need a copy constructor
    //TODO bitch, TODO
    tree::node temp = x->dequeue();
    tree::node temp2 = temp;
    tree::node *root = new tree::node(temp.get_data(), temp.get_frequency(), temp.get_left(), temp.get_right());
    tree *huffman_tree = new tree(root);

    in_file.close();

    cout << "starting expreiment" << endl;
    do
    {
        cout << "fuck1" << endl;
        temp = *temp.get_right();
        cout << temp << endl;
    } while (!temp.get_right()->is_leaf());
    temp = *temp.get_right();
    cout << "the holy grail" << temp << endl;

    temp = temp2;
    do
    {
        temp = *temp.get_left();
        cout << temp << endl;
    } while (!temp.get_left()->is_leaf());
    if (temp.is_leaf())
    {
    }
    else
    {
        temp = *temp.get_left();
    }
    cout << "the holy grail" << temp << endl;

    return huffman_tree;
}