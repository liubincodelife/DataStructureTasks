#include <iostream>
#include "ListStack.hpp"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ListStack<int> listStack;
    cout << "push data into stack:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        listStack.push(i);
        cout << i << " ";
    }
    cout << endl;

    if (listStack.isEmpty())
        cout << "The stack is empty!!! " << endl;
    else
        cout << "The stack is not empty!!! " << endl;

    cout << "pop data out to stack:" << endl;
    size_t stackSize = listStack.getSize();
    for (int i = 0; i < stackSize; i++)
    {
        int retValue = listStack.top();
        listStack.pop();
        cout << retValue << " ";
    }
    cout << endl;
    
    getchar();
    return 0;
}