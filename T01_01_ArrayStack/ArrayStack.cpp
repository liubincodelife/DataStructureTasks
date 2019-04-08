#include <iostream>
#include "ArrayStack.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ArrayStack<int> arrayStack(10);
    cout << "push data into stack:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        arrayStack.push(i);
        cout << i << " ";
    }
    cout << endl;
    
    if (arrayStack.isEmpty())
        cout << "The stack is empty!!! " << endl;
    else
        cout << "The stack is not empty!!! " << endl;

    if (arrayStack.isFull())
        cout << "The stack is full!!! " << endl;
    else
        cout << "The stack is not full!!! " << endl;
    cout << "pop data out to stack:" << endl;
    size_t stackSize = arrayStack.getSize();
    for (int i = 0; i < stackSize; i++)
    {
        int retValue = arrayStack.top();
        arrayStack.pop();
        cout << retValue << " ";
    }
    cout << endl;
    
    getchar();
    return 0;
}