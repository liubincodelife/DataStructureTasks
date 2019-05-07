#include <iostream>

using namespace std;

#define MAX_WEIGHT  9

int weight[5] = { 2, 2, 4, 6, 2};
int total_weight = -1;

void backPack(int index, int currentWeight, int items[], int num, int toleranceWeight)
{
    if (currentWeight == toleranceWeight || index == num)
    {
        if (currentWeight > total_weight)
        {
            total_weight = currentWeight;
        }
        return;
    }
    backPack(index + 1, currentWeight, items, num, toleranceWeight);
    if (currentWeight+items[index] <= toleranceWeight)
    {
        backPack(index + 1, currentWeight + items[index], items, num, toleranceWeight);
    }
}

void test1()
{
    int count = sizeof(weight) / sizeof(int);
    backPack(0, 0, weight, count, MAX_WEIGHT);
    cout << "the max weight is:"<< total_weight <<endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}