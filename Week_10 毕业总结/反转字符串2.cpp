class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += (k << 1)) {
            int l = i, r = min(i + k - 1, n - 1);
            while (l < r) {
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};