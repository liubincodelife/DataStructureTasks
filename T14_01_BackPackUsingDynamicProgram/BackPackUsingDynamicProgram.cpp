#include <iostream>

using namespace std;
#define MAX_WEIGHT  9

int weight[5] = { 2, 2, 4, 6, 3 };

int BackPackBasic(int items[], int num, int toleranceWeight)
{
    bool states[MAX_WEIGHT + 1] = { false };
    states[0] = true;
    states[items[0]] = true;
    for (int i = 1; i < num; i++)
    {
        for (int j = toleranceWeight - items[i]; j >= 0; j--)
        {
            if (states[j] == true)
            {
                states[j + items[i]] = true;
            }
        }
    }

    //Êä³ö½á¹û
    for (int i = toleranceWeight; i >= 0; --i)
    {
        if (states[i] == true)
            return i;
    }
    return 0;
}

void test1()
{
    int length = sizeof(weight) / sizeof(int);
    int maxWeight = BackPackBasic(weight, length, MAX_WEIGHT);
    cout << "max weight of the backpack is: "<< maxWeight << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}