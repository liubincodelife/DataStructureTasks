#include <iostream>

using namespace std;

class HeapSort
{
public:
    void buildHeap(int array[], int length)
    {
        //�ӵ�һ����Ҷ�ӽڵ㿪ʼ�ѻ�
        for (int i = length/2; i >= 1; --i)
        {
            heapify(array, length, i);
        }
    }

    //�󶥶Ѷѻ�
    void heapify(int array[], int length, int i)
    {
        while (true)
        {
            int maxPos = i;
            if (2*i <= length && array[i] < array[2*i])
            {
                maxPos = 2 * i;
            }

            if ((2*i+1) <=length && array[maxPos] < array[2*i+1])
            {
                maxPos = 2 * i + 1;
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

    void sort(int array[], int length)
    {
        //����
        buildHeap(array, length);
        //����
        int k = length;
        while (k > 1)
        {
            swap(&array[1], &array[k]);
            --k;
            heapify(array, k, 1);
        }
    }

protected:
private:
};

void test1()
{
    cout << "test1 running......"<< endl;
    int array[] = { 0, 13, 15, 12, 33, 16, 27, 19, 8, 7, 6, 1, 2, 5, 21 };
    int length = sizeof(array) / sizeof(int) - 1;
    HeapSort heapSort;
    heapSort.sort(array, length);
    for (int i = 1; i <= length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}