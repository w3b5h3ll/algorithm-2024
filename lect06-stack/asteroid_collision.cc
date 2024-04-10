#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/asteroid-collision/description/
class Solution
{
public:
    vector<int> AsteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        int stack_flag = 0;
        int equal = 0;
        int cur_flag = 0;

        for (int i = 0; i < asteroids.size(); i++)
        {
            if (s.empty())
            {
                s.push(asteroids[i]);
                continue;
            }

            cur_flag = asteroids[i] > 0 ? 1 : -1;
            int top = s.top();
            stack_flag = top > 0 ? 1 : -1;
            if (cur_flag == stack_flag)
            {
                s.push(asteroids[i]);
                continue;
            }
            else
            {
                if (cur_flag > 0)
                {
                    s.push(asteroids[i]);
                    continue;;
                }
                else
                {
                    while (s.size() != 0)
                    {
                        int temp_top = s.top();
                        int temp_flag = temp_top > 0 ? 1 : -1;
                        
                        // 同类型符号，负数
                        if (temp_flag < 0)
                        {
                            s.push(asteroids[i]);
                            break;
                        }
                        
                        if (temp_top == abs(asteroids[i]))
                        {
                            s.pop();
                            break;
                        }
                        if (temp_top > abs(asteroids[i]))
                        {
                            break;
                        }
                        s.pop();
                        // 小行星都被撞碎了
                        if (s.size() == 0)
                        {
                            s.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }

        // 存储结果
        vector<int> result;
        while (s.size() != 0)
        {
            result.push_back(s.top());
            s.pop();
        }

        reverse(begin(result), end(result));
        return result;
    }
};

int main()
{

    // vector<int> asteroids = {10, 2, -5}; // 10
    // vector<int> asteroids = {5, 10, -5}; // 5 10
    // vector<int> asteroids = {8, -8}; // 
    // vector<int> asteroids = {-2, -1, 1, 2}; // -2 -1 1 2
    // vector<int> asteroids = {1, -1, 1, -2}; // -2
    vector<int> asteroids = {-2, -2, 1, -2}; // -2 -2 -2
    vector<int> result = Solution().AsteroidCollision(asteroids);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}