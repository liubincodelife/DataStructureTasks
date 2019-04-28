#include <iostream>
#include "MaxHeap.hpp"
#include "MinHeap.hpp"

using namespace std;

void testMaxHeap()
{
    cout << "test MaxHeap running......" << endl;
    //int array[] = { 3, 5, 2, 1, 6, 7, 9, 8, 0, 4 };
    int array[] = { 13, 15, 12, 33, 16, 27, 19, 8, 7, 6, 1, 2, 5, 21};
    int length = sizeof(array) / sizeof(int);
    MaxHeap maxHeap;
    for (int i = 0; i < length; i++)
    {
        maxHeap.insert(array[i]);
    }
    cout << "heap data before remove top:" << endl;
    maxHeap.print();

    cout << "heap data after remove top:" << endl;
    maxHeap.removeMax();
    maxHeap.print();
}

void testMinHeap()
{
    cout << "test MinHeap running......" << endl;
    //int array[] = { 3, 5, 2, 1, 6, 7, 9, 8, 0, 4 };
    int array[] = { 13, 15, 12, 33, 16, 27, 19, 8, 7, 6, 1, 2, 5, 21 };
    int length = sizeof(array) / sizeof(int);
    MinHeap minHeap;
    for (int i = 0; i < length; i++)
    {
        minHeap.insert(array[i]);
    }
    cout << "heap data before remove top:" << endl;
    minHeap.print();

    cout << "heap data after remove top:" << endl;
    minHeap.removeMin();
    minHeap.print();
}

int main(int argc, char** argv)
{
    testMaxHeap();
    testMinHeap();
    getchar();
    return 0;
}