/*
leetcode 77
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

*/

class Solution {
public:
    void backtrack(vector<vector<int>>& res,vector<int>& single,int& n,int& k,int i){
        if(single.size()==k){
            res.push_back(single);
            return;
        }
        for(;i<=n-(k-single.size())+1;i++){             //i<=n没有减枝，有多余的时间，可以优化搜索起点的上界
            single.push_back(i);
            backtrack(res,single,n,k,i+1);
            single.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n==0||k==0) return res;
        vector<int> single;
        int i = 1;
        backtrack(res,single,n,k,i);
        return res;
    }
};