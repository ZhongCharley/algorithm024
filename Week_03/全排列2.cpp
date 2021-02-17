/*
leetcode 47
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/

class Solution {
public:
    void FullPermutation(vector<vector<int>>& res,vector<int>& single, vector<int>& nums,vector<int>& used){
        if(single.size()==nums.size()){
            res.push_back(single);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==0) continue;  //比全排列多的一行，0可以1也可以，0的速度更快
            if(used[i]) continue;
            used[i]=1;
            single.push_back(nums[i]);
            FullPermutation(res,single,nums,used);
            used[i]=0;
            single.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()==0) return res;
        vector<int> used(nums.size(),0);
        vector<int> single;
        FullPermutation(res,single,nums,used);
        return res;
    }
};