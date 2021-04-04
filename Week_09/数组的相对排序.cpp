class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0), res;
        int n = arr1.size(), m = arr2.size(), count = 0;
        for (auto num : arr1) {
            freq[num]++; //此时arr1中的数组是按照升序排列的
        }
        for (int i = 0; i < m; ++i) {
            while (freq[arr2[i]]) {
                res.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        } 
        for (int i = 0; i < 1001; ++i) {
            while(freq[i]) {
                res.push_back(i);
                freq[i]--;
            }
        }
        return res;
    }
};