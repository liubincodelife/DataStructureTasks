#include <iostream>
#include <vector>

using namespace std;

int mymax(int x, int y, int z)
{
    int maxv = INT_MIN;
    if (x > maxv)
    {
        maxv = x;
    }
    if (y > maxv)
    {
        maxv = y;
    }
    if (z > maxv)
    {
        maxv = z;
    }

    return maxv;
}

int longestCommonSubstring(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<vector<int>> maxLength(n, vector<int>(m));
    for (int j = 0; j < m; ++j) //初始化第0行
    {
        if (a[0] == b[j])
        {
            maxLength[0][j] = 1;
        }
        else if (j != 0)
        {
            maxLength[0][j] = maxLength[0][j - 1];
        }
        else
        {
            maxLength[0][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == b[0])
        {
            maxLength[i][0] = 1;
        }
        else if (i != 0)
        {
            maxLength[i][0] = maxLength[i - 1][0];
        }
        else
        {
            maxLength[i][0] = 0;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i] == b[j])
            {
                maxLength[i][j] = mymax(maxLength[i - 1][j], maxLength[i][j - 1], maxLength[i - 1][j - 1] + 1);
            }
            else
            {
                maxLength[i][j] = mymax(maxLength[i - 1][j], maxLength[i][j - 1], maxLength[i - 1][j - 1]);
            }
        }
    }
    return maxLength[n - 1][m - 1];
}

void test()
{
    string a = "abkjcl";
    string b = "abcuio";
    int maxLength = longestCommonSubstring(a, b);
    cout << "the max substring length is: " << maxLength << endl;
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}