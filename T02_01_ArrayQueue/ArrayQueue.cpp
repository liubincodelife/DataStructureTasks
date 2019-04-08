#include <iostream>
#include "ArrayQueue.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ArrayQueue<int> arrayQueue(10);

    cout << "the data push in queue is: "<< endl;
    for (int i = 1; i <= 10; i++)
    {
        arrayQueue.push(i);
        cout << i;
    }
    cout << endl;
    cout << "the data pop out queue is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        int retValue = arrayQueue.front();
        arrayQueue.pop();
        cout << retValue;
    }
    cout << endl;

    getchar();
    return 0;
}