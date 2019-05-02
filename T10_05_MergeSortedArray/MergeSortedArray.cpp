#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE    100
#define N           5

struct HeapNode
{
    int m_nValue;
    int currentArray;
    int nextIndex;
    HeapNode() :m_nValue(0), currentArray(0), nextIndex(0) {};
};

class MergeSortedArray
{
public:
    MergeSortedArray(int capacity = MAX_SIZE):size(capacity), count(0)
    {
        HeapNode* pHeapNode = new HeapNode();
        heapVector.push_back(pHeapNode);
    }

    ~MergeSortedArray()
    {
        if(!heapVector.empty())
        {
            heapVector.clear();
        }
    }

    bool isEmpty()
    {
        return (count == 0) ? true : false;
    }

    bool isFull()
    {
        return (count == size) ? true : false;
    }

    int getSize()
    {
        return count;
    }

    void push(int data)
    {
        
    }

    void heapify(int array[], int count, int i)
    {
        
    }

    void swap(int* a, int* b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    void print()
    {
        
    }
protected:
private:
    vector<HeapNode*> heapVector;
    int size;
    int count;
};

void test1()
{
    int array[][5] = { {1, 3, 5, 7, 9},
                       {2, 4, 6, 8, 10} };
    int k = sizeof(array) / sizeof(array[0]);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}