class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        int length = nums.size(), _max = 1;
        vector<int> dp(length, 1);
        for (int i = 1; i < length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            _max = max(_max, dp[i]);
        }
        return _max;
        */
        int len = nums.size(), end = 0;
        if (len < 2) {
            return len;
        }

        vector<int> tail;
        tail.push_back(nums[0]);
        
        for (int i = 1; i < len; i++) {
            //升序
            if (nums[i] > tail[end]) {
                tail.push_back(nums[i]);
                end++;
            }
            else {
                //替换
                int left = 0, right = end;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (tail[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                tail[left] = nums[i];
            }
        }
        return end + 1;
    }
};