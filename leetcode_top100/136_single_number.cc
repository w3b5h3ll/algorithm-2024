#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

class Solution
{
public:
    int SingleNumber(vector<int> &nums)
    {
        vector<int> s;
        // 先排序，后进行栈弹出
        sort(nums.begin(), nums.end());
        for (auto num : nums)
        {
            if (s.empty())
            {
                s.push_back(num);
                continue;
            }
            while (!s.empty())
            {
                if (num == s.back())
                {
                    s.pop_back();
                    break;
                }
                else
                {
                    s.push_back(num);
                    break;
                }
            }
        }

        return s.back();
    }

    // 确实，这道题应该使用异或运算，位运算
    int SingleNumberByXor(vector<int> &nums)
    {
        int ret = 0;
        for (auto num : nums)
        {
            ret ^= num;
        }
        return ret;
    }
};

int main()
{
    auto start = chrono::high_resolution_clock::now();
    vector<int> input = {2, 2, 1};
    int ret = Solution().SingleNumber(input);
    cout << ret << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "running: " << duration.count() << " s" << endl;

    ret = Solution().SingleNumberByXor(input);
    cout << ret << endl;
    auto end_xor = chrono::high_resolution_clock::now();
    duration = end_xor - end;
    cout << "xor running: " << duration.count() << " s" << endl;

    return 0;
}