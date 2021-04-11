class Solution {
public:
    /*
    //暴力
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size() || s.empty() || p.empty()) return {};
        vector<int> ans;
        vector<int> dict(26, 0);
        for (int i = 0; i < p.size(); i++) {
            dict[p[i] - 'a']++;
        }
        for (int i = 0; i < (s.size() - p.size() + 1); i++) {
            if (isValid(s, dict, p.size(), i)) ans.push_back(i);
        }
        return ans;
    }

    bool isValid(string s, vector<int> dict, int length, int pos) {
        int i = 0;
        while(i < length) {
            if (dict[s[i + pos] - 'a'] == 0) return false;
            dict[s[i + pos] - 'a']--;
            i++;
        }
        return true;
    }
    */
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        int pLength = p.size(), sLength = s.size();
        vector<int> ans;
        vector<int> sd(26), pd(26);
        for (int i = 0; i < pLength; i++) {
            ++sd[s[i] - 'a'];
            ++pd[p[i] - 'a'];
        }
        if (pd == sd) ans.push_back(0);

        for (int i = pLength; i < sLength; i++) {
            //右边进入
            ++sd[s[i] - 'a'];
            //左边出
            --sd[s[i - pLength] - 'a'];

            //判断相等时O(1)的时间复杂度
            if (pd == sd) ans.push_back(i - pLength + 1);
        }
        return ans;
    }
};