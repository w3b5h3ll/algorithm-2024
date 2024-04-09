// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/asteroid-collision/solutions/1663442/xing-xing-peng-zhuang-by-leetcode-soluti-u3k0/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 巧妙，将入栈行星与栈顶行星区分开来考虑了
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> AsteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;
        for (auto aster : asteroids)
        {
            bool alive = true;
            // 行星存在，stack存在且大于0，说明两个行星移动方向相反；如果栈顶元素大于等于-aster，行星发生爆炸；如果栈顶元素小于等于-aster，说明不爆炸，执行出栈
            while (alive && aster < 0 && !st.empty() && st.back() > 0)
            {
                alive = st.back() < -aster; // aster 是否存在
                if (st.back() <= -aster)
                { // 栈顶行星爆炸
                    st.pop_back();
                }
            }
            if (alive)
            {
                st.push_back(aster);
            }
        }
        return st;
    }
};

int main()
{

    // vector<int> asteroids = {10, 2, -5}; // 10
    // vector<int> asteroids = {5, 10, -5}; // 5 10
    // vector<int> asteroids = {8, -8}; // 
    // vector<int> asteroids = {-2, -1, 1, 2}; // -2 -1 1 2
    vector<int> asteroids = {1, -1, 1, -2}; // -2
    // vector<int> asteroids = {-2, -2, 1, -2}; // -2 -2 -2
    vector<int> result = Solution().AsteroidCollision(asteroids);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}