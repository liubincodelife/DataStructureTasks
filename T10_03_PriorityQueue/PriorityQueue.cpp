#include <iostream>

using namespace std;

#define MAX_SIZE    20

class PriorityQueue
{
public:
    PriorityQueue(int capacity = MAX_SIZE):size(capacity), count(0)
    {
        array = new int[capacity + 1]();
    }

    ~PriorityQueue()
    {
        if (array != nullptr)
        {
            delete[] array;
        }
    }

    bool isEmpty()
    {
        return (count == 0) ? true : false;
    }

    bool isFull()
    {
        return (count == size) ? true : false;
    }

    int getSize()
    {
        return count;
    }

    void push(int data)
    {
        if (isFull())
            return;
        array[++count] = data;
        int i = count;
        while ((i / 2) > 0 && array[i] > array[i/2])
        {
            swap(&array[i], &array[i/2]);
            i = i / 2;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        int maxValue = array[1];
        array[1] = array[count];
        --count;
        heapify(array, count, 1);

        return maxValue;
    }

    void heapify(int array[], int count, int i)
    {
        while (true)
        {
            int maxPos = i;
            if ((i*2) <= count && array[i] < array[i*2])
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

    void swap(int* a, int* b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void print()
    {
        for (int i = 1; i <= count; i++)
        {
            std::cout << array[i] << "  ";
        }
        std::cout << std::endl;
    }
protected:
private:
    int* array;
    int size;
    int count;
};

void test1()
{
    cout << "test1 running....." << endl;
    int array[] = { 13, 15, 12, 33, 16, 27, 19, 8, 7, 6, 1, 2, 5, 21 };
    int length = sizeof(array) / sizeof(int);
    PriorityQueue priorityQueue;

    for (int i = 0; i < length; i++)
    {
        priorityQueue.push(array[i]);
    }

    for (int i = 0; i < length; i++)
    {
        int retValue = priorityQueue.pop();
        cout << retValue << " ";
    }
}

int main(int aegc, char** argv)
{
    test1();
    getchar();
    return 0;
}