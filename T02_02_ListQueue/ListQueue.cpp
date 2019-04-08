#include <iostream>
#include "ListQueue.hpp"

using namespace std;

int main(int argc, char** argv)
{
    ListQueue<int> listQueue;
    cout << "the data push in queue is: " << endl;
    for (int i = 1; i <= 10; i++)
    {
        listQueue.push(i);
        cout << i;
    }
    cout << endl;

    cout << "the data pop out queue is: " << endl;
    for (int i = 0; i < 10; i++)
    {
        int retValue = listQueue.front();
        listQueue.pop();
        cout << retValue;
    }
    cout << endl;

    getchar();
    return 0;
}