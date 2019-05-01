#pragma once
#include <iostream>

#define MAX_SIZE    20

class MaxHeap
{
public:
    MaxHeap(int capacity = MAX_SIZE);
    ~MaxHeap();
    void insert(int data);
    int removeMax();
    void heapify(int array[], int count, int i);
    void swap(int* a, int* b);
    void print();
protected:
private:
    int* array;
    int size;
    int count;
};

MaxHeap::MaxHeap(int capacity):size(capacity), count(0)
{
    array = new int[capacity + 1]();
}

MaxHeap::~MaxHeap()
{
    if (array != nullptr)
    {
        delete[] array;
    }
}

void MaxHeap::insert(int data)
{
    if (count >= size)
    {
        return;
    }
    array[++count] = data;
    int i = count;
    while ((i / 2) > 0 && array[i] > array[i/2])
    {
        swap(&array[i], &array[i/2]);
        i = i / 2;
    }
}

//自上往下堆化
void MaxHeap::heapify(int array[], int count, int i)
{
    while (true)
    {
        int maxPos = i;
        if (i*2 <= count && array[i] < array[i*2])
        {
            maxPos = i * 2;
        }

        if ((i*2+1) <= count && array[maxPos] < array[i*2+1])
        {
            maxPos = i * 2 + 1;
        }
        if (maxPos == i)
        {
            break;
        }
        swap(&array[i], &array[maxPos]);
        i = maxPos;
    }
}

int MaxHeap::removeMax()
{
    if (count == 0)
    {
        return -1;
    }
    int maxValue = array[1];
    array[1] = array[count];
    --count;
    heapify(array, count, 1);

    return maxValue;
}

void MaxHeap::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void MaxHeap::print()
{
    for (int i = 0; i <= count; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}
