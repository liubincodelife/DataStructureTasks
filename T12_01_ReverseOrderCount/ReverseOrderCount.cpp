#include <iostream>

using namespace std;

int num = 0;

void merge(int array[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int* sortedArray = new int[high - low + 1]();
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
        {
            sortedArray[k++] = array[i++];
        } 
        else
        {
            num += (mid - i + 1);
            sortedArray[k++] = array[j++];
        }
    }

    while (i <= mid)
    {
        sortedArray[k++] = array[i++];
    }

    while (j <= high)
    {
        sortedArray[k++] = array[j++];
    }
    for (i = 0; i <= high - low; i++)
    {
        array[i] = sortedArray[i];
    }
    delete[] sortedArray;
}

void mergeSort(int array[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    merge(array, low, mid, high);
}

int countReverseOrder(int array[], int length)
{
    mergeSort(array, 0, length - 1);
    return num;
}

void test1()
{
    int array[] = { 1, 5, 6, 2, 3, 4 };
    int length = sizeof(array) / sizeof(int);
    int count = countReverseOrder(array, length);
    cout << "reverse order count is: " << count << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}