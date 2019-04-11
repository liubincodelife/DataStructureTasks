#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> numMap;
        vector<int> retIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            int minus = target - nums[i];
            if (numMap.find(minus) != numMap.end() && numMap[minus] != i)
            {
                retIndex.push_back(numMap[minus]);
                retIndex.push_back(i);
                return retIndex;
            }
            numMap[nums[i]] = i;
        }

        return retIndex;
    }
protected:
private:
};

void test()
{
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    int target = 7;
    Solution solution;
    vector<int> index = solution.twoSum(nums, target);
    cout << "the index is: ";
    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
}

int main(int argc, char** argv)
{
    test();
    getchar();
    return 0;
}