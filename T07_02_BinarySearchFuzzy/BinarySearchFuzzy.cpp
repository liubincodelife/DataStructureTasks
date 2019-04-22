#include <iostream>

using namespace std;

//查找第一个等于value的元素
int Binary_Search_Fuzzy0(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (array[mid] > value)
        {
            high = mid - 1;
        }
        else if (array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0 || array[mid - 1] < value)
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

//查找最后一个等于value的元素
int Binary_Search_Fuzzy1(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (array[mid] > value)
        {
            high = mid - 1;
        } 
        else if(array[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == length - 1 || array[mid + 1] > value)
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

//查找第一个大于等于value的元素
int Binary_Search_Fuzzy2(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (array[mid] >= value)
        {
            if ((mid == 0) || (array[mid - 1] < value))
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

//查找最后一个小于等于value的元素
int Binary_Search_Fuzzy3(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (array[mid] > value)
        {
            high = mid - 1;
        } 
        else
        {
            if (mid == length - 1 || array[mid + 1] > value)
            {
                return mid;
            } 
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}

void test1()
{
    cout << "find the first element equals to value:"<< endl;
    int array[9] = { 1, 3, 5, 6, 6, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search_Fuzzy0(array, length, 6);
    cout << "the index of the number is: "<< index << endl;
}

void test2()
{
    cout << "find the last element equals to value:" << endl;
    int array[9] = { 1, 3, 5, 6, 6, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search_Fuzzy1(array, length, 6);
    cout << "the index of the number is: " << index << endl;
}

void test3()
{
    cout << "find the first element bigger than value:" << endl;
    int array[9] = { 1, 3, 5, 6, 6, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search_Fuzzy2(array, length, 6);
    cout << "the index of the number is: " << index << endl;
}

void test4()
{
    cout << "find the last element smaller than value:" << endl;
    int array[9] = { 1, 3, 5, 6, 6, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search_Fuzzy3(array, length, 6);
    cout << "the index of the number is: " << index << endl;
}

int main(int argc, char** argv)
{
    test1();
    test2();
    test3();
    test4();
    getchar();
    return 0;
}