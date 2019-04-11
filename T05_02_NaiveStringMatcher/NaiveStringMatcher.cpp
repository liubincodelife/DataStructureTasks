#include <iostream>
#include <string>

using namespace std;

//返回第一个匹配的字符串索引
int NaiveStringMatch(string& str1, string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int loopTimes = len1 - len2;

    for (int i = 0; i <= loopTimes; i++)
    {
        bool flag = false;
        for (int j = 0; j < len2; j++)
        {
            if (str1[i+j] == str2[j])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
    }

    return -1;
}

//返回所有字符串出现的索引
void NaiveStringMatch2(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    int loopTimes = len1 - len2;
    for (int i = 0; i <= loopTimes; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (str1[i+j] != str2[j])
            {
                break;
            }
        }
        if (j == len2)
        {
            cout << "found the string index is "<< i << endl;
        }
    }
}

void test1()
{
    cout << "test1 running......" << endl;
    string str1 = "abcdefghijk";
    string str2 = "efgh";

    int index = NaiveStringMatch(str1, str2);
    if (index != -1)
    {
        cout << "found string " << str2 << "  in string " << str1 << endl;
        cout << "the index is "<< index << endl;
    }
}

void test2()
{
    cout << "test2 running......" << endl;
    string str1 = "abcdefgabcdefg";
    string str2 = "defg";

    NaiveStringMatch2(str1, str2);
}

int main(int argc, char** argv)
{
    test1();
    test2();
    getchar();
    return 0;
}