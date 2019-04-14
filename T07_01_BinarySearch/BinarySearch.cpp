#include <iostream>

using namespace std;

int Binary_Search(int array[], int length, int value)
{
    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
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

void test()
{
    int array[10] = { 1, 3, 4, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search(array, length, 6);
    cout << "the index of the number is: " << index << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}