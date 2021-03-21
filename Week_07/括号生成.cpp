class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string kuohao;
        digui(ans, n, kuohao, 1, 1);
        return ans;
    }
    void digui(vector<string>& ans, int& n, string kuohao, int left, int right) {
        if (right > n) {
            ans.push_back(kuohao);
            return; 
        }
        if (left <= n) {
            kuohao.push_back('(');
            digui(ans, n, kuohao, left + 1, right);
            kuohao.pop_back();
        }
        if (right < left) {
            kuohao.push_back(')');
            digui(ans, n, kuohao, left, right + 1);
        }
        return;
    }
};