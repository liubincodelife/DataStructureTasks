#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findKthLargest(int array[], int length, int k) 
{
    int high = length;
    int low = 0;
    while (low < high) 
    {
        int i = low;
        int j = high - 1;
        int pivot = array[low];
        while (i <= j) 
        {
            while (i <= j && array[i] >= pivot)
                i++;
            while (i <= j && array[j] < pivot)
                j--;
            if (i < j)
                swap(array[i++], array[j--]);
        }

        swap(array[low], array[j]);

        if (j == k - 1)
            return array[j];
        else if (j < k - 1)
            low = j + 1;
        else
            high = j;
    }
}

void test()
{
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int k = 2;
    int retValue = findKthLargest(array, length, k);
    cout << "the kth number in the array is: "<< retValue << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}