/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
leetcode46
回溯基本用法，注意用了之后要pop，并且状态置为0
*/
class Solution {
public:
    void FullPermutation(vector<vector<int>>& res,vector<int>& single, vector<int>& nums,vector<int>& used){
        if(single.size()==nums.size()){
            res.push_back(single);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            single.push_back(nums[i]);
            FullPermutation(res,single,nums,used);
            used[i]=0;
            single.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        vector<int> used(nums.size(),0);
        vector<int> single;
        FullPermutation(res,single,nums,used);
        return res;
    }

};