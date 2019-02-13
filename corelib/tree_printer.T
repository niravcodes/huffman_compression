//written unwillingly for debugging purposes
#include <iostream>
using namespace std;

template <class T>
void print_tree(T *tree)
{
    if (tree->get_root()->is_leaf())
    {
        cout << *tree->get_root();
    }
    else
    {
        T *x = new T(tree->get_root()->get_right());
        T *y = new T(tree->get_root()->get_left());
        cout << "|" << endl;
        print_tree(x);
        cout << "--" << endl;
        print_tree(y);
    }
}