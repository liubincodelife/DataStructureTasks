#include <iostream>

using namespace std;

//二分查找循环方式
int Binary_Search_Loop(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        //int mid = (low + high) / 2;
        int mid = low + (high - low) / 2;
        if (array[mid] == value)
        {
            return mid;
        }
        else if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

//二分查找递归方式
int Binary_Search_Recursive(int array[], int low, int high, int value)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (array[mid] == value)
    {
        return mid;
    }
    else if (array[mid] < value)
    {
        low = mid + 1;
        Binary_Search_Recursive(array, low, high, value);
    }
    else
    {
        high = mid - 1;
        Binary_Search_Recursive(array, low, high, value);
    }

}

int Binary_Search_Recursive(int array[], int length, int value)
{
    return Binary_Search_Recursive(array, 0, length - 1, value);
}

void test()
{
    int array[7] = { 1, 3, 4, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index1 = Binary_Search_Loop(array, length, 6);
    cout << "Loop:the index of the number is: " << index1 << endl;

    int index2 = Binary_Search_Recursive(array, length, 6);
    cout << "Recursive:the index of the number is: " << index2 << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}