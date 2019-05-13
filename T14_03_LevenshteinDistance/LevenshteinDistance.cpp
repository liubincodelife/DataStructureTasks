#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mymin(int x, int y, int z)
{
    int minv = INT_MAX;
    if (x < minv)
    {
        minv = x;
    } 
    if(y < minv)
    {
        minv = y;
    }
     if (z < minv)
     {
         minv = z;
     }
     return minv;
}

int lvsDistDP(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<vector<int>> minDist(n, vector<int>(m));

    for (int j = 0; j < m; ++j) //初始化第0行
    {
        if (a[0] == b[j])
        {
            minDist[0][j] = j;
        }
        else if (j != 0)
        {
            minDist[0][j] = minDist[0][j - 1] + 1;
        }
        else  //当j==0且a[0] != b[0]时
        {
            minDist[0][j] = 1;
        }
    }

    for (int i = 0; i < n; ++i)  //初始化第0列
    {
        if (a[i] == b[0])
        {
            minDist[i][0] = i;
        } 
        else if(i != 0)
        {
            minDist[i][0] = minDist[i-1][0] + 1;
        }
        else
        {
            minDist[i][0] = 1;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i] == b[j])
            {
               minDist[i][j] = mymin(minDist[i - 1][j] + 1, minDist[i][j - 1] + 1, minDist[i - 1][j - 1]);
            } 
            else
            {
                minDist[i][j] = mymin(minDist[i - 1][j] + 1, minDist[i][j - 1] + 1, minDist[i - 1][j - 1] + 1);
            }
        }
    }
    return minDist[n - 1][m - 1];
}

void test1()
{
    string a = "mitcmu";
    string b = "mtacnu";
    int lvsDistance = lvsDistDP(a, b);
    cout << "the lvsDist between a&b is: " << lvsDistance << endl;
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}