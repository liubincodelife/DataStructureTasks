#pragma once

#define MAX_SIZE    10


template<typename T> class ExpansionArray
{
public:
    ExpansionArray(int size=MAX_SIZE);
    ~ExpansionArray();
    bool appendData(T item);
    bool isFull();
    int getSize();
    void print();
private:
    T* m_array;
    int m_size;
    int m_index;
};

template<typename T>
ExpansionArray<T>::ExpansionArray(int size = MAX_SIZE):m_size(size), m_index(0)
{
    m_array = new T[size]();
}

template<typename T>
ExpansionArray<T>::~ExpansionArray()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
}

template<typename T>
bool ExpansionArray<T>::appendData(T item)
{
    if (isFull())
    {
        cout << "starting expansion the array" << endl;
        int newSize = m_size * 2;
        T* newArray = new T[newSize](); //分配内存时加上()则可将内存初始化为0，否则为随机值
        for (int i = 0; i < m_size; i++)
        {
            newArray[i] = m_array[i];
        }
        m_size = newSize;
        delete[] m_array;
        m_array = newArray;
        m_array[m_index++] = item;
    }
    else
    {
        m_array[m_index++] = item;
    }

    return true;
}

template<typename T>
bool ExpansionArray<T>::isFull()
{
    return (m_index >= m_size);
}

template<typename T>
int ExpansionArray<T>::getSize()
{
    return m_size;
}

template<typename T>
void ExpansionArray<T>::print()
{
    cout << "the size of array is: "<< m_size << endl;
    for (int i = 0; i < m_size; i++)
    {
        cout << m_array[i] << " ";
    }
    cout << endl;
}