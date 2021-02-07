class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hasht;
        //边查找，边存储
        for(int i=0;i<nums.size();i++){
            auto it=hasht.find(target-nums[i]);
            if(it!=hasht.end()){
                return{it->second,i};
            }
            hasht[nums[i]]=i;
        }
        return {};
    }
};