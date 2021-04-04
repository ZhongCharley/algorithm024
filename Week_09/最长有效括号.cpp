class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0;
        //第一个为右括号，需要弹出
        stk.push(-1);

        for (int i = 0; i < s.size(); ++i) {
            //左括号入栈
            if (s[i] == '(') stk.push(i);
            else {
                //右括号出栈，保留离左括号最近的右括号
                stk.pop();
                //为空，说明左边为有效括号，记录此时的右括号为初始点
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    //更新答案
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};