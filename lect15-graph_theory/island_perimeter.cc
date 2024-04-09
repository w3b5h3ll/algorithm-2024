
// https://leetcode.cn/problems/island-perimeter/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 使用迭代，针对每个格子进行遍历，看其4个方向是否为边界或水域，是的话，边+1
class Solution
{
    // 常量表达式
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};

public:
    int IslandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int tx = i + dx[k];
                        int ty = j + dy[k];
                        // 边界条件判断
                        if (tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty])
                        {
                            cnt += 1;
                        }
                    }
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int ret = Solution().IslandPerimeter(grid);
    cout << ret;

    return 0;
}