class Solution {
public:
    string longestPalindrome(string s) {
        int max_left, max = 0;
        for (int center = 0; center < 2 * s.size() - 1; center++) {
            int left = center /  2;
            int right = left + center % 2;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (max <= right - left) max = right - left, max_left = left ;
                left--;
                right++;     
            }
        }
        return s.substr(max_left,max + 1);
    }
};