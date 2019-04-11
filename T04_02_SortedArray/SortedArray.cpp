#include <iostream>
#include "SortedArray.hpp"

using namespace std;

int main(int argc, char** argv)
{
    SortedArray<int> sortedArray(10);
    int size = sortedArray.getSize();
    for (int i = 0; i < size; i++)
    {
        sortedArray.insertData(i, i+1);
    }

    sortedArray.print();
    sortedArray.insertData(10, 20);
    sortedArray.print();

    sortedArray.insertData(3, 30);
    sortedArray.print();

    sortedArray.deleteData(3);
    sortedArray.print();

    getchar();
    return 0;
}