#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    /**
     * @brief 暴力法解题：两数之和
     * 
     * @param nums 
     * @param target 
     * @return vector<int> 
     */
    vector<int> TwoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                /* code */
                if (nums[i] == (target - nums[j]))
                {
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                    break;
                }
            }
        }
        return result;
    }
};