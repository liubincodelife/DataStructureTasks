#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 4;

vector<vector<int>> matrix = {
    {1, 3, 5, 9},
    {2, 1, 3, 4},
    {5, 2, 6, 7},
    {6, 8, 4, 3}
};

vector<vector<int>> mem(n, vector<int>(n));

int minDist1(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return matrix[0][0];
    }
    if (mem[i][j] > 0)
    {
        return mem[i][j];
    }
    int minLeft = INT_MAX;
    if (j-1 >= 0)
    {
        minLeft = minDist1(i, j - 1);
    }

    int minUp = INT_MAX;
    if (i - 1 >= 0)
    {
        minUp = minDist1(i - 1, j);
    }

    int currentMinDist = matrix[i][j] + min(minLeft, minUp);
    mem[i][j] = currentMinDist;
    return currentMinDist;
}

int minDist2()
{
    int sum = 0;
    for (int j = 0; j < n; ++j) //初始化第0行
    {
        sum += matrix[0][j];
        mem[0][j] = sum;
    }
    sum = 0;
    for (int i = 0; i < n; ++i) //初始化第0列
    {
        sum += matrix[i][0];
        mem[i][0] = sum;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            mem[i][j] = matrix[i][j] + min(mem[i - 1][j], mem[i][j - 1]);
        }
    }

    return mem[n - 1][n - 1];
}

void test1()
{
    cout << "test1 is running......" << endl;
    int minDistance = minDist1(n - 1, n - 1);
    cout << "the minimum path is:" << minDistance << endl;
}

void test2()
{
    cout << "test2 is running......" << endl;
    int minDistance = minDist2();
    cout << "the minimum path is:" << minDistance << endl;
}


int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}