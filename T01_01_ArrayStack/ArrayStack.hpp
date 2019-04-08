#pragma once

#define MAX_SIZE    10

template <typename T> class ArrayStack
{
public:
    ArrayStack();
    ArrayStack(size_t n);
    ~ArrayStack(void);
    
    T top();
    void pop();
    void push(T item);
    bool isEmpty(void);
    bool isFull(void);
    size_t getSize(void);
private:
    T* array;
    int head;
    size_t maxSize;
};

template <typename T>
ArrayStack<T>::ArrayStack(void): maxSize(MAX_SIZE), head(-1)
{
    array = new T[MAX_SIZE];
}


template <typename T>
ArrayStack<T>::ArrayStack(size_t size) : maxSize(size), head(-1)
{
    array = new T[size];
}

template <typename T>
ArrayStack<T>::~ArrayStack(void)
{
    if (array != nullptr)
    {
        delete[] array;
    }
}


template <typename T>
T ArrayStack<T>::top(void)
{
    if (!isEmpty())
    {
        return array[head];
    }
    else
    {
        cout << "The stack is empty!!!"<< endl;
        return NULL;
    }
}

template <typename T>
void ArrayStack<T>::push(T item)
{
    if (!isFull())
    {
        head++;
        array[head] = item;
    }
    else
    {
        cout << "The stack is full!!!" << endl;
    }
    
}

template <typename T>
void ArrayStack<T>::pop(void)
{
    if (!isEmpty())
    {
        head--;
    }
    else
    {
        cout << "The stack is empty!!!" << endl;
    }
}

template <typename T>
bool ArrayStack<T>::isEmpty(void)
{
    return head == -1;
}

template <typename T>
bool ArrayStack<T>::isFull(void)
{
    return head == (maxSize - 1);
}

template <typename T>
size_t ArrayStack<T>::getSize()
{
    return head + 1;
}
