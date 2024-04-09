#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
// 逆波兰表达式，即后缀表达式求值
// 如：tokens = ["2","1","+","3","*"] >> (2 + 1) * 3
// 由于运算符总是与最近的操作数进行操作，使用stack可以很好的解决该问题
class Solution
{
    int calculate(int n1, int n2, string opt)
    {
        if ("+" == opt)
        {
            return n1 + n2;
        }
        if ("-" == opt)
        {
            return n1 - n2;
        }
        if ("*" == opt)
        {
            return n1 * n2;
        }
        if ("/" == opt)
        {
            return n1 / n2;
        }

        return 0;
    }

public:
    int EvalRpn(vector<string> &tokens)
    {
        stack<string> s;
        // cout << tokens.size() << endl;
        for (int i = 0; i < tokens.size(); i++)
        {
            // cout << tokens[i] << endl;
            if ("+" == tokens[i] || "-" == tokens[i] || "*" == tokens[i] || "/" == tokens[i])
            {
                int n1 = stoi(s.top());
                s.pop();
                int n2 = stoi(s.top());
                s.pop();
                s.push(to_string(calculate(n2, n1, tokens[i])));
                continue;
            }
            else
            {
                s.push(tokens[i]);
            }
        }
        return stoi(s.top());
    }
};

int main()
{
    // 2 + 1 * 3 = 9;
    vector<string> rpn = {"2", "1", "+", "3", "*"};
    int ret = Solution().EvalRpn(rpn);
    cout << ret;

    return 0;
}