#include <iostream>

using namespace std;

int Binary_Search_Fuzzy(int array[], int length, int value)
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

void test()
{
    int array[10] = { 1, 3, 5, 6, 7, 8, 9 };
    int length = sizeof(array) / sizeof(int);
    int index = Binary_Search_Fuzzy(array, length, 6);
    cout << "the index of the number is: "<< index << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}