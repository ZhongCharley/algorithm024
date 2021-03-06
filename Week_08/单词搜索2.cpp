/*
//dfs + 减枝
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size(), col = board[0].size(), words_size = words.size(), min1 = words[0].size(), count = 0;
        unordered_set<string> dict, words_dict;
        vector<string> ans;

        for (int i = 0; i < words_size; i++) {
            if (min1 > words[i].size()) min1 = words[i].size();
            words_dict.insert(words[i]);
        };
        
        if (min1 > row * col) return {}; //整个网格数量少于最少的单词的大小，就没必要再找了
        for (int i = 0; i < row; i++) {
            if (count == words_size) break; //找完了就不用再找了
            for (int j = 0; j < col; j++) {
                for (auto target : words_dict) {
                    if (board[i][j] == target[0]) {
                        bool findit = false;
                        dfs(board, i, j, target, 0, dict, findit);
                        if (findit) count++;
                    }
                }
            }
        }
        for(auto i : dict) ans.push_back(i);
        return ans;
    }

    void dfs (vector<vector<char>>& board, int row, int col, string& target, int words_p, unordered_set<string>& dict,bool& findit) {
        if (findit) return ; //找到了就不用再找了
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != target[words_p]) return ;
        if (words_p == (target.size() - 1) && board[row][col] == target[words_p]) {
            dict.insert(target);
            findit = true;
            return ;
        }
        else {
            board[row][col] = '/';
            dfs(board, row + 1, col, target, words_p + 1, dict, findit);
            dfs(board, row - 1, col, target, words_p + 1, dict, findit);
            dfs(board, row , col + 1, target, words_p + 1, dict, findit);
            dfs(board, row , col - 1, target, words_p + 1, dict, findit);
            board[row][col] = target[words_p];
        }
        return ;
    }
};
*/
// tire树 感觉和dfs + 减枝没差
class Solution {
 public:
    struct Node {
        vector<Node*> children;
        int numOfNode;
        bool end;

        Node() : children(26) { 
            end = false; 
            numOfNode = 0;
        }

        ~Node() {
            for (auto& ptr : children) {
                if (ptr) {
                    delete ptr;
                    ptr = NULL;
                }
            }
        }
    };

    struct Tries {
        Node* root;
        Tries() { root = new Node; }

        void insert(string str) {
            Node* th = root;
            for (auto c : str) {
                if (th->children[c - 'a'] == NULL) {
                    th->numOfNode++;
                    th->children[c - 'a'] = new Node;
                }
                th = th->children[c - 'a'];
            }
            th->end = true;
        }

        bool search(string str) {
            Node* th = root;
            for (auto c : str) {
                if (th->children[c - 'a'] == NULL) {
                    return false;
                }
                th = th->children[c - 'a'];
            }
            return th->end;
        }

        Node* search(Node* node, char c) {
            if (node->children[c - 'a'] == NULL || node->numOfNode == 0) {
                return NULL;
            }
            return node->children[c - 'a'];
        }

        void traversal(Node* node, vector<Node*>& vec) {
            if (node == NULL) {
                return;
            }
            vec.push_back(node);
            for (auto& child : node->children) {
                if (!child) {
                    traversal(child, vec);
                }
            }
        }

        ~Tries() {
            delete root;
        }
    };

    Tries trie;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void backTrack(vector<string>& ans, Node* node, string temp, vector<vector<char>>& board, int i, int j) { 
        if (node == NULL) {
            return;
        }
        Node* newNode = trie.search(node, board[i][j]);
        if (newNode == NULL) {
            return;
        }
        temp.push_back(board[i][j]);
        // 添加完立刻判断
        if (newNode->end) {
            ans.emplace_back(temp);
            newNode->end = false;
            // 可能有单词共享前缀，不能return
        }
        //   直接修改当前board;
        board[i][j] -= 26;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[nx].size() || board[nx][ny] < 'a') {
                continue;
            }
            backTrack(ans, newNode, temp, board, nx, ny);
        }
        board[i][j] += 26;
        temp.pop_back();
        //   若子节点为叶节点, 表示该路径已经便利完毕，可以删除
        if (newNode->numOfNode == 0) {
            --node->numOfNode;
            delete newNode;
            node->children[board[i][j] - 'a'] = NULL;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string& str : words) {
            trie.insert(str);
        }
        vector<string> ans;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                backTrack(ans, trie.root, "", board, i, j);
            }
        }
        return ans;
    }
};