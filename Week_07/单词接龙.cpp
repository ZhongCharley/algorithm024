class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //双向BFS
        unordered_set<string> begin, end; 
        unordered_set<string> worddict(wordList.begin(), wordList.end()); //将字典转为set方便查找
        
        if (worddict.find(endWord) == worddict.end()) return 0;

        //初始化
        int ans = 1;
        begin.insert(beginWord); //从开始端搜索
        end.insert(endWord); //从结束端搜索

        //两个集合不为空
        while(!begin.empty() && !end.empty()) {
            if (begin.size() > end.size()) {
                swap(begin, end);             //交替进行搜索
            }
            unordered_set<string> temp;
            //标准的bfs
            for (string s : begin) {
                for (int j = 0; j < s.size(); j++) {
                    char old = s[j];
                    for (char new_char = 'a'; new_char <= 'z'; new_char++) {
                        s[j] = new_char ;
                        if (end.find(s) != end.end()) {
                            return ++ans;   //如果在结束端发现了该值，说明二者相遇
                        }

                        if (worddict.find(s) != worddict.end()) {
                            temp.insert(s);
                            worddict.erase(s);
                        }
                    }
                    s[j] = old;
                }
            }
            begin = temp; //更新队列
            ans ++;  //跟新步长
        }
        return 0;
    }
};