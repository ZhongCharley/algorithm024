/*
leetcode：242
*/

class Solution {
public:
    #if 0
    bool isAnagram(string s, string t) {
        //相当于用数组实现hash
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;

    }
    #endif
    //unoredered_hash直接用
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;
        for(int i=0;i<max(s.size(),t.size());i++)
            map[s[i]]++,map[t[i]]--;
        for(auto it:map)
            if(it.second!=0) return false;
        return true;

    }


};