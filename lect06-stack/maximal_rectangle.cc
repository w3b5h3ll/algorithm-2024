#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/maximal-rectangle/
// 求面积，往往需要定义长和宽
// 基于柱状图中最大矩形，进行一步步求解
// 只有保证，每一层的底层存在，这个柱长度才有意义，否则，height为0

class Solution
{
public:
    vector<int> StringToIntVec(string &str)
    {
        vector<int> temp;
        for (auto c : str)
        {
            if (c == '0')
            {
                temp.push_back(0);
            }
            else
            {
                temp.push_back(1);
            }
        }
        return temp;
    }

    int MaximalRectangle(vector<string> &matrix_string)
    {
        vector<vector<int>> matrix;
        if (matrix_string.size() == 0)
        {
            return 0;
        }
        
        for (auto height : matrix_string)
        {
            vector<int> temp_vector = StringToIntVec(height);
            matrix.push_back(temp_vector);
        }
        int n = matrix.size();
        int m = matrix[0].size();

        int max_area = 0;

        vector<int> heights(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // 判断该层的底部是否存在
                if (matrix[i][j] == 1)
                {
                    heights[j] += 1;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, LargestRectangleArea(heights));
        }
        return max_area;
    }

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
    vector<string> heights = {"10100", "10111", "11111", "10010"};

    int ret = Solution().MaximalRectangle(heights);
    cout << ret << endl;

    return 0;
}