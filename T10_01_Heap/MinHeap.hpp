#pragma once
#include <iostream>

#define MAX_SIZE    20

class MinHeap
{
public:
    MinHeap(int capacity = MAX_SIZE);
    ~MinHeap();
    void insert(int data);
    int removeMin();
    void heapify(int array[], int count, int i);
    void swap(int* a, int* b);
    void print();
protected:
private:
    int* array;
    int size;
    int count;
};

MinHeap::MinHeap(int capacity) :size(capacity), count(0)
{
    array = new int[capacity + 1]();
}

MinHeap::~MinHeap()
{
    if (array != nullptr)
    {
        delete[] array;
    }
}

void MinHeap::insert(int data)
{
    if (count >= size)
    {
        return;
    }
    array[++count] = data;
    int i = count;
    while ((i / 2) > 0 && array[i] < array[i/2])
    {
        swap(&array[i], &array[i/2]);
        i = i / 2;
    }
}

//自上往下堆化
void MinHeap::heapify(int array[], int count, int i)
{
    while (true)
    {
        int minPos = i;
        if (i * 2 <= count && array[i] > array[i * 2])
        {
            minPos = i * 2;
        }

        if ((i * 2 + 1) <= count && array[minPos] > array[i * 2 + 1])
        {
            minPos = i * 2 + 1;
        }
        if (minPos == i)
        {
            break;
        }
        swap(&array[i], &array[minPos]);
        i = minPos;
    }
}

int MinHeap::removeMin()
{
    if (count == 0)
    {
        return -1;
    }
    int minValue = array[1];
    array[1] = array[count];
    --count;
    heapify(array, count, 1);

    return minValue;
}

void MinHeap::swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void MinHeap::print()
{
    for (int i = 0; i <= count; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}

