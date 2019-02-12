#include <iostream>
#include "../corelib/tree.h"
#include "../corelib/priority_queue.h"
using namespace std;

int main()
{
    cout << "Testing priority queue" << endl;
    priority_queue queue;
    tree::leaf m(65, 20, NULL, NULL);
    queue.enqueue(m);

    cout << (int)queue.dequeue().get_data() << endl;
}