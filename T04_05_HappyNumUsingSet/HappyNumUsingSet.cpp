#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int num)
    {
        unordered_set<int> numSet;
        if (num == 1)
            return true;
        while (num != 1)
        {
            int sum = getSum(num);
            if (numSet.find(sum) != numSet.end())  //求和之后的数在set中，导致死循环直接返回
            {
                return false;
            }
            else
            {
                numSet.insert(sum);
                num = sum;
            }
        }

        return true;
    }
protected:
private:
    int getSum(int num)
    {
        int sum = 0;
        while (num)
        {
            int a = num % 10;
            sum += a * a;
            num = num / 10;
        }

        return sum;
    }
};

void test()
{
    Solution solution;
    bool retValue = solution.isHappy(19);
    if (retValue)
    {
        cout << "the number is a happy number......" << endl;
    }
    else
    {
        cout << "the number is not a happy number......" << endl;
    }
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}