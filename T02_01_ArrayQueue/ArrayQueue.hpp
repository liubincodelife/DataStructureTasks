#pragma once

#define MAX_SIZE    10

template <typename T> class ArrayQueue
{
public:
    ArrayQueue(int size = MAX_SIZE);
    ~ArrayQueue();

    T front();
    T pop();
    void push(T item);
    bool isEmpty();
    bool isFull();
    int getSize();
private:
    int head;
    int tail;
    int m_size;
    T* array;
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int size = MAX_SIZE):head(0), tail(0), m_size(size)
{
    array = new T(size);
}

template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
    if (array != nullptr)
    {
        delete[] array;
    }
}

template <typename T>
T ArrayQueue<T>::front()
{
    if (isEmpty())
        return NULL;
    return array[head];
}

template <typename T>
T ArrayQueue<T>::pop()
{
    if (isEmpty())
        return NULL;
    T retValue = array[head];
    head++;
    return retValue;
}

template <typename T>
void ArrayQueue<T>::push(T item)
{
    if (isFull())
    {
        cout << "the queue is full!!!" << endl;
        return;
    }
    else
    {
        //若尾指针已到数组最后，则进行数据搬移
        if (tail == m_size)
        {
            for (int i = head; i < tail; i++)
                array[i - head] = array[i];
            tail -= head;
            head = 0;
        }
        
        array[tail] = item;
        tail++;
    }

}

template <typename T>
bool ArrayQueue<T>::isEmpty()
{
    return tail == head;
}

template <typename T>
bool ArrayQueue<T>::isFull()
{
    return (tail == m_size && head == 0);
}

template <typename T>
int ArrayQueue<T>::getSize()
{
    return tail - head;
}

