/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //用栈的方法，在中序遍历种要记住，左链入栈（左，root，右）
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        auto p = root;
        while(p||!st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            auto node = st.top();
            st.pop();
            res.emplace_back(node->val);
            p = node->right;
        }
        return res;
    }
};