/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
leetcode：589
*/

class Solution {
public:
    void traversal(Node* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);  
        for(int i = 0;i < cur->children.size();i++){
            traversal(cur->children[i],vec);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};