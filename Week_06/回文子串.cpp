//leetcode647
class Solution {
public:
    int countSubstrings(string s) {
        /*
        //暴力法，时间复杂度n的三次方
        int ans = s.size();
        for (int left = 0; left < s.size()-1; left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (isSubstrings(s,left,right)) ans++;
            }
        }
        return ans;
    }
    bool isSubstrings(string& s, int left, int right) {
        while(left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    */
    /*
        //动态规划
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(), false));
        int ans = 0;

        for (int j = 0; j < s.size(); j++) 
            for (int i = 0; i <= j; i++) {
                if (s[j] == s[i] && ((j - i < 2) || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        return ans;
    */
        //中心点扩展法,考虑中心为奇数或者偶数两种情况
        int ans = 0;
        for (int center = 0; center < 2 * s.size() - 1; center++) {
            int left = center /  2;
            int right = left + center % 2;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};