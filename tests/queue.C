#include "../corelib/priority_queue.h"
#include "../corelib/tree.h"
#include <iostream>
using namespace std;

void interactive_q()
{
    char c = 0;
    unsigned data, freq;
    tree::node x;
    queue q;
    while (c != 'q')
    {
        cout << endl;
        cout << "a to enqueue, s to dequeue" << endl
             << "i to print whole queue, q to quit" << endl;
        cin >> c;
        if (c == 'a')
        {
            cout << "input data freq" << endl;
            cin >> data >> freq;
            x = tree::node(data, freq, 0, 0);
            q.enqueue(x);
        }
        else if (c == 's')
        {
            if (q.is_empty())
            {
                cout << "empty queue" << endl;
            }
            //dequeue should not crash if empty
            cout << q.dequeue() << endl;
            if (q.is_empty())
            {
                cout << "empty queue" << endl;
            }
        }
        else if (c == 'i')
        {
            while (!q.is_empty())
            {
                cout << q.dequeue() << endl;
            }
            cout << "q emptied" << endl;
        }
    }
}
void simple_test()
{
    queue q;
    tree::node x(2, 10, 0, 0);
    q.enqueue(x);
    x = tree::node(1, 4, 0, 0);
    q.enqueue(x);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}
int main()
{
    interactive_q();
}