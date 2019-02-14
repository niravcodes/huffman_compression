//written unwillingly for debugging purposes
#include <iostream>
using namespace std;

string display[500];

template <class T>
void print_tree(T *tree)
{
    if (tree->get_root()->is_leaf())
    {
        cout << *tree->get_root();
    }
    else
    {
        T *x = new T(tree->get_root()->get_left());
        T *y = new T(tree->get_root()->get_right());
        cout << "|";
        print_tree(x);
        cout << endl;
        cout << "---------------------------------------------|";
        print_tree(y);
        cout << endl;
    }
    cout << endl;
}

void print_subtree(tree::node n, int indent)
{
    if (n.is_leaf())
    {
    }
}