class Trie {
/*
1.字典树是一个多叉树，如果是26个字母的话，那么最复杂的情况就是26叉树
2.每一个点存储的是当前的字符
3.插入和搜索类似
4.需要有一个结束标志位
*/
private:
    Trie* child[26];
    bool tag;

public:
    /** Initialize your data structure here. */
    Trie() {
        this -> tag = false;
        memset(child, 0, sizeof(child));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (!word.empty()) {
            Trie* node = this; //指向当前根节点
            for (char ch : word) {
                unsigned i = ch - 'a'; //从a开始的26个字母
                if (node -> child[i] == nullptr) {
                    node -> child[i] = new Trie;
                }
                node = node -> child[i];
            }
            node -> tag = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            unsigned i = ch - 'a';
            if (node -> child[i] == nullptr) return false;
            node = node -> child[i];
        }
        return node -> tag == 1 ? true : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            unsigned i = ch - 'a';
            if (node -> child[i] == nullptr) return false;
            node = node -> child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */