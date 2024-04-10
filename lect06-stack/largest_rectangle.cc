#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 单调栈的思想，从小到大顺序
// 每次计算以柱高为标准的矩形面积
// 如何确定栈顶柱高为顶的最高矩阵面积？该矩阵的宽度一定是，从栈顶柱子的两边出发直到遇到比该柱高矮的柱子所夹成的宽度。因为单调栈中保存的柱高是递增的，所以栈中位于栈顶柱子前面的柱子一定比栈顶柱子矮，同样当前扫描到的柱子也矮于位于栈顶的柱子，所以顶柱子为顶的最高矩阵的宽度就确定了，那么面积也就确定了。

class Solution
{
public:
    int LargestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        st.push(-1);
        int max_area = 0;
        for (int i = 0; i < n; i++)
        {
            // 栈顶元素比当前元素高
            // 2 1 5 6 2 3 ... 0
            // 0 1 2 3 4 5 ... size
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                /* code */
                // 出栈，并计算
                int height = heights[st.top()];
                st.pop();
                // cout << i << ", " << st.top() << endl;
                int width = i - st.top() - 1;
                max_area = max(max_area, width * height);
            }
            st.push(i);
        }

        return max_area;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ret = Solution().LargestRectangleArea(heights);
    cout << ret << endl;

    return 0;
}