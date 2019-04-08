#pragma once

#define MAX_SIZE    10

template<typename T> class CircleQueue
{
public:
    CircleQueue(int size = MAX_SIZE);
    ~CircleQueue();
    T front();
    void pop();
    void push(T item);
    bool isEmpty();
    bool isFull();
    int getSize();
private:
    T* array;
    int m_head;
    int m_tail;
    int m_size;
};

template<typename T>
CircleQueue<T>::CircleQueue(int size = MAX_SIZE):m_size(size),m_head(0),m_tail(0)
{
    array = new T(size);
}

template<typename T>
CircleQueue<T>::~CircleQueue()
{
    if (array != nullptr)
    {
        delete[] array;
    }
}

template<typename T>
T CircleQueue<T>::front()
{
    if (isEmpty())
        return NULL;
    T item = array[m_head];
    return item;
}

template<typename T>
void CircleQueue<T>::pop()
{
    if (isEmpty())
        return;
    m_head++;
}

template<typename T>
void CircleQueue<T>::push(T item)
{
    if (isFull())
    {
        return;
    }
    array[m_tail] = item;
    m_tail = ((m_tail + 1) % m_size);
}

template<typename T>
bool CircleQueue<T>::isEmpty()
{
    return (m_tail == m_head);
}

template<typename T>
bool CircleQueue<T>::isFull()
{
    return ((m_tail + 1) % m_size == m_head);
}

template<typename T>
int CircleQueue<T>::getSize()
{
    return ((m_tail - m_head + m_size) % m_size);
}
