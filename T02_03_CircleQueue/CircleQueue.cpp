#include <iostream>
#include "CircleQueue.hpp"

using namespace std;

int main(int argc, char** argv)
{
    CircleQueue<int> circleQueue(10);

    cout << "the data push in queue is: " << endl;
    for (int i = 1; i < 10; i++)
    {
        circleQueue.push(i);
        cout << i;
    }
    cout << endl;
    cout << "the data pop out queue is: " << endl;
    for (int i = 0; i < 9; i++)
    {
        int retValue = circleQueue.front();
        circleQueue.pop();
        cout << retValue;
    }
    cout << endl;

    getchar();
    return 0;
}