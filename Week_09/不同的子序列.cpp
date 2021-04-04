class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty()||t.empty()) return 0;
        int col = s.size(), row = t.size();
        vector<vector<long long>> dp(row, vector<long long>(col, 0));
        if (s[0] == t[0]) dp[0][0] = 1;
        for (int i = 1; i < col; i++) {
            if (s[i] == t[0]) dp[0][i] = dp[0][i - 1] + 1;
            else dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (s[j] == t[i]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                    
                }
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};