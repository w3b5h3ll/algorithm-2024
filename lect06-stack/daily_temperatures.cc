// https://leetcode.cn/problems/daily-temperatures/description/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 暴力法，逐个遍历 n^2
// 输入过长，导致超时
class Solution
{
public:
    vector<int> DailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ret;
        for (int i = 0; i < temperatures.size(); i++)
        {
            int cur = temperatures[i];
            int temp_result = 0;
            for (int j = i + 1; j < temperatures.size(); j++)
            {
                if (temperatures[j] > cur)
                {
                    temp_result = j - i;
                    break;
                }
            }
            ret.push_back(temp_result);
        }
        return ret;
    }

    // 使用栈解决，单调栈，其只保存index即可。弹栈时即可获取天数，并使用另外一个vector保存结果
    vector<int> SolveByStack(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            // 只要当前元素比stack顶的元素大就进行弹栈，并获取结果
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int prev_index = s.top();
                ans[prev_index] = i - prev_index;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};

int main()
{
    vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ret = Solution().SolveByStack(input);
    for (auto n : ret)
    {
        cout << n << endl;
    }

    return 0;
}