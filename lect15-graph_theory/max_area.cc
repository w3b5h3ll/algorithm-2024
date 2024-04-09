// 函数命名：StartRpc()
// 取值和设值函数与变量名保持一致：int count() void set_count(int count)

#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/max-area-of-island/
// 二维数组表示岛屿
// DFS: 4个方向探索与之相连的土地，递归操作，为了确保每个土地访问不超过一次，每次经过一块土地时，将其值置为0
class Solution
{
    int dfs(vector<vector<int>> &grid, int cur_i, int cur_j)
    {
        // 终止条件
        if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
        {
            return 0;
        }
        // 遍历过，置其值为0
        // 定义4个方向
        grid[cur_i][cur_j] = 0;
        int di[4] = {0, 0, 1, -1};
        int dj[4] = {1, -1, 0, 0};
        int ans = 1;
        for (int i = 0; i != 4; i++)
        {
            int next_i = cur_i + di[i];
            int next_j = cur_j + dj[i];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }

    // 使用队列进行操作
    int bfs(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                queuei.push(i);
                queuej.push(j);

                while (!queuei.empty())
                {
                    int cur_i = queuei.front();
                    int cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();

                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                    {
                        continue;
                    }
                    ++cur;
                    grid[cur_i][cur_j] = 0;

                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index < 4; index++)
                    {
                        int next_i = cur_i + di[index];
                        int next_j = cur_j + dj[index];
                        queuei.push(next_i);
                        queuej.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }

public:
    // 使用引用&,直接操作原始变量，而不是副本。减少内存开销
    int MaxAreaOfIsland(vector<vector<int>> &grid)
    // int MaxAreaOfIsland(vector<vector<int>> grid)
    {
        // int ans = 0;
        // for (int i = 0; i != grid.size(); i++)
        // {
        //     for (int j = 0; j != grid[0].size(); j++)
        //     {
        //         ans = max(ans, dfs(grid, i, j));
        //     }
        // }

        // return ans;
        return bfs(grid);
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    int ret = Solution().MaxAreaOfIsland(grid);
    cout << ret;
    return 0;
}
