class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> begin, end_s;
        unordered_set<string> library(bank.begin(), bank.end());
        char gen[4] = {'A', 'C', 'G', 'T'};
        int ans = 1;

        if (library.find(end) == library.end()) return -1;
        begin.insert(start);
        end_s.insert(end);
        library.erase(end);

        while(!begin.empty() && !end_s.empty()) {
            if (begin.size() > end_s.size()) {
                swap(begin, end_s);
            }
            unordered_set<string> temp;
            for (string s : begin) {
                for (int i = 0; i < 8; i++) {
                    char ch = s[i];
                    for (char j : gen) {
                        s[i] = j;
                        if (end_s.find(s) != end_s.end()) return ans;
                        if (library.find(s) != library.end()) {
                            temp.insert(s);
                            library.erase(s);
                        }
                    s[i] = ch;
                    }
                }
            }
            ans ++;
            begin = temp;
        }
        return -1;
    }
};