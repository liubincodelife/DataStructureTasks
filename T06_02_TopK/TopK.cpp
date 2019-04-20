#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//TopK问题非递归法
int findKthLargest(int array[], int length, int k) 
{
    int high = length;
    int low = 0;
    while (low < high) 
    {
        //定义前后两个游标，分别定为比pivot小和比pivot大的数字的位置
        int i = low;
        int j = high - 1;
        int pivot = array[low];
        while (i <= j) 
        {
            //从前往后查找，直到找到比pivot小的数停止
            while (i <= j && array[i] >= pivot)
                i++;
            //从后向前查找，直到找到比pivot大的数停止
            while (i <= j && array[j] < pivot)
                j--;
            //将上面找到的两个数交换位置，使比pivot大的数在左边，比pivot小的数在右边
            if (i < j)
                swap(array[i++], array[j--]);
        }
        //将pivot移至中间
        swap(array[low], array[j]);

        if (j == k - 1)
            return array[j];
        else if (j < k - 1)
            low = j + 1;
        else
            high = j;
    }
}

//TopK问题递归法
int partition(int array[], int low, int high)
{
    int pivot = array[low];
    while (low < high)
    {
        while (low < high && array[high] <= pivot)
        {
            high--;
        }
        array[low] = array[high];

        while (low < high && array[low] >= pivot)
        {
            low++;
        }
        array[high] = array[low];
    }

    array[low] = pivot;
    return low;
}

int findTopK(int array[], int low, int high, int k)
{
    if (low < high)
    {
        int pos = partition(array, low, high);
        int len = pos - low + 1;
        if (len == k)
        {
            return array[pos];
        }
        else if (len < k)
        {
            findTopK(array, pos + 1, high, k - len);
        }
        else
        {
            findTopK(array, low, pos - 1, k);
        }
    }
}

void test1()
{
    cout << "test1 is running......" << endl;
    int array[10] = { 3, 0, 2, 1, 6, 4, 8, 5, 9, 7};
    int length = sizeof(array) / sizeof(int);
    int k = 2;
    int retValue = findKthLargest(array, length, k);
    cout << "the kth number in the array is: "<< retValue << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    int array[10] = { 3, 0, 2, 1, 6, 4, 8, 5, 9, 7 };
    int length = sizeof(array) / sizeof(int);
    int k = 2;
    int retValue = findTopK(array, 0, length - 1, k);
    cout << "the kth number in the array is: " << retValue << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}