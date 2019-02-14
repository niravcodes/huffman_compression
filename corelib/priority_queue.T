template <class T>
priority_queue<T>::priority_queue()
{
    priority_queue<T>::alphabets = new T[256];
    priority_queue<T>::top = 0;
}
template <class T>
priority_queue<T>::~priority_queue()
{
    delete[] priority_queue<T>::alphabets;
}
template <class T>
void priority_queue<T>::enqueue(T &lf)
{
    priority_queue<T>::alphabets[top++] = lf;
}
template <class T>
T priority_queue<T>::dequeue()
{
    if (is_empty())
        return T(); //return empty node if nothing
    if (priority_queue<T>::top == 1)
        return priority_queue<T>::alphabets[--top];

    unsigned index = 0;
    T smallest = priority_queue<T>::alphabets[index];
    for (int i = 0; i < priority_queue<T>::top; i++)
    {
        if (priority_queue<T>::alphabets[i] < smallest)
        {
            smallest = priority_queue<T>::alphabets[i];
            index = i;
        }
    }
    priority_queue<T>::alphabets[index] = priority_queue<T>::alphabets[--top];
    return smallest;
}
template <class T>
bool priority_queue<T>::is_empty()
{
    return !priority_queue<T>::top;
}
template <class T>
unsigned priority_queue<T>::element_count()
{
    return priority_queue<T>::top;
}

template <class T>
bool queue<T>::is_empty()
{
    return !(bottom > priority_queue<T>::top);
}
template <class T>
queue<T>::queue()
{
    priority_queue<T>();
    bottom = 0;
}
template <class T>
void queue<T>::enqueue(T &a)
{
    priority_queue<T>::alphabets[bottom++] = a;
    if (bottom >= QUEUE_MAXSIZE)
        bottom = 0;
}
template <class T>
T queue<T>::dequeue()
{
    if (is_empty())
        return T();

    if (priority_queue<T>::top >= (QUEUE_MAXSIZE - 1))
    {
        priority_queue<T>::top = 0;
        return priority_queue<T>::alphabets[QUEUE_MAXSIZE - 1];
    }
    return priority_queue<T>::alphabets[priority_queue<T>::top++];
}