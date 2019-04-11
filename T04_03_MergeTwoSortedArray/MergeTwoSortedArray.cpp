#include <iostream>
#include "MergeTwoSortedArray.hpp"

using namespace std;

int main(int argc, char** argv)
{
    MergeTwoSortedArray<int> mergeTwoSortArray;
    int array1[3] = { 1, 2, 3 };
    int array2[3] = { 4, 5, 6 };
    int* mergeArray;
    mergeArray = mergeTwoSortArray.mergeArrays(array1, 3, array2, 3);
    cout << "two arrays after merge is: "<< endl;
    for (int i = 0; i < 6; i++)
    {
        cout << mergeArray[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}