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
*/
/*
通过队列辅助实现层序遍历，记录每一层的节点，先入先出
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>  que;
        if(root==NULL) return {};
        que.push(root);
        vector<vector<int>> res;
        while(!que.empty()){
            //队列会变动
            int layer_size = que.size();
            vector<int> layer_value;
            for(int i=0;i<layer_size;i++){
                //得到当前层的值
                Node* node = que.front();
                que.pop();
                layer_value.push_back(node->val);
                //将下一层的节点压入队列
                for(auto it:node->children)
                    que.push(it);
            }
            res.push_back(layer_value);
        }
        return res;
    }
};