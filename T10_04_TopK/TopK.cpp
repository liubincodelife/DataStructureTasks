#include <iostream>

using namespace std;

#define MAX_SIZE    20

class TopK
{
public:
    TopK(int capacity = MAX_SIZE):size(capacity), count(0)
    {
        array = new int[capacity + 1]();
    }

    ~TopK()
    {
        if (array != nullptr)
        {
            delete[] array;
        }
    }

    void push(int data)
    {
        if (count == size)
        {
            if (data > array[1])
            {
                array[1] = data;
                heapify(array, count, 1);
            }
        }
        else
        {
            array[++count] = data;
            int i = count;
            while ((i / 2) > 0 && array[i] < array[i / 2])
            {
                swap(&array[i], &array[i / 2]);
                i = i / 2;
            }
        }
    }

    void heapify(int array[], int count, int i)
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

    void swap(int* a, int* b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int getTopKValue()
    {
        if (count < size)
            return -1;
        return array[1];
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
    cout << "test1 running......" << endl;
    int array[] = { 13, 15, 12, 33, 16, 27, 19, 8, 7, 6, 1, 2, 5, 21 };
    int length = sizeof(array) / sizeof(int);
    int k = 3;
    TopK topK(k);
    for (int i = 0; i < length; i++)
    {
        topK.push(array[i]);
    }

    int kthValue = topK.getTopKValue();
    cout << "top kth value is: "<< kthValue << endl;

    cout << "top k value is: ";
    topK.print();
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}