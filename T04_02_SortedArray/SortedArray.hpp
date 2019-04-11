#pragma once

#define MAX_SIZE    10

template <typename T> class SortedArray
{
public:
    SortedArray(int size = MAX_SIZE);
    ~SortedArray();
    bool isFull();
    bool insertData(int index, T item);
    bool deleteData(int index);
    bool editData(int index, T item);
    T find(int index);
    T* expansionArray(int size);
    void print();
    int getSize();

private:
    T* m_array;
    int m_size;
    int m_count;
};

template <typename T> 
SortedArray<T>::SortedArray(int size = MAX_SIZE):m_size(0), m_count(0)
{
    if (m_array != nullptr)
        return;
    m_array = new T[size]();
    m_size = size;
}

template <typename T>
SortedArray<T>::~SortedArray()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
    }
}

template <typename T>
bool SortedArray<T>::isFull()
{
    return m_count == m_size;
}

template <typename T>
bool SortedArray<T>::insertData(int index, T item)
{
    if (index < 0 || index > m_count)
        return false;
    if (isFull())
    {
        //数组已满，开始扩容
        expansionArray(m_size * 2);
    }

    for (int i = m_count - 1; i >= index; i--)
    {
        m_array[i + 1] = m_array[i];
    }

    m_array[index] = item;
    ++m_count;

    return true;
}

template <typename T>
bool SortedArray<T>::deleteData(int index)
{
    if (index < 0 || index > m_count)
        return false;
    for (int i = index + 1; i < m_count; i++)
    {
        m_array[i - 1] = m_array[i];
    }
    --m_count;
    if (m_count == m_size / 4 && m_size / 2 != 0)
    {
        //动态缩容
        expansionArray(m_size / 2);
    } 

    return true;
}

template <typename T>
bool SortedArray<T>::editData(int index, T item)
{
    if (index < 0 || index >= m_count)
        return flase;
    m_array[index] = item;

    return true;
}

template <typename T>
T SortedArray<T>::find(int index)
{
    if (index < 0 || index >= m_count)
        return -1;
    T item = m_array[index];

    return item;
}

template <typename T>
T* SortedArray<T>::expansionArray(int size)
{
    T* newArray = new T[size]();
    for (int i = 0; i < m_count; i++)
    {
        newArray[i] = m_array[i];
    }
    delete[] m_array;
    m_array = newArray;
    m_size = size;

    return m_array;
}

template <typename T>
void SortedArray<T>::print()
{
    cout << "the size of array is: "<< m_size << endl;
    for (int i = 0; i < m_count; i++)
    {
        cout << m_array[i] << " ";
    }
    cout << endl;
}

template <typename T>
int SortedArray<T>::getSize()
{
    return m_size;
}


