#include <iostream>

using namespace std;

int result[8] = { 0 };

bool isOK(int row, int column)
{
    int leftUp = column - 1;
    int rightUp = column + 1;
    for (int i = row-1; i >= 0; --i)
    {
        if (result[i] == column) //判断第i行的column列是否有棋子
            return false;
        if (leftUp >= 0)
        {
            if (result[i] == leftUp) //判断第i行的左上是否有棋子
                return false;
        }
        if (rightUp < 8)
        {
            if (result[i] == rightUp) //判断第i行的右上是否有棋子
                return false;
        }
        --leftUp;
        ++rightUp;
    }
    return true;
}

void printQueens()
{
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            if (result[row] == column)
                cout << "Q ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void calEightQueens(int row)
{
    if (row == 8)
    {
        printQueens();
        return;
    }

    for (int column = 0; column < 8; column++)
    {
        if (isOK(row, column))  //判断是否满足要求
        {
            result[row] = column;
            calEightQueens(row + 1);
        }
    }
}

void test1()
{
    calEightQueens(0);
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}