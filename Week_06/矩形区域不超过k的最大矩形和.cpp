//leetcode 363
/*
1.行比列多，所以外循环列，内循环行
2.固定左右两列，再对行进行求和操作
3.结合最大子序和的结论，前面的和（加上自己）比自己小还不如另起炉灶
*/
/*
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //暴力法
        int row = matrix.size(), col = matrix[0].size(), max_num = INT_MIN;
        for (int left  = 0; left < col; left++) {
            vector<int> row_value(row, 0);
            for (int right = left; right < col; right++) {
                for (int row_i = 0; row_i < row; row_i++) {
                    row_value[row_i] += matrix[row_i][right]; 
                }
                max_num = max(max_num, dp_max(row_value, k));
            }
        }
        return max_num;
    }
    int dp_max(const vector<int>& row_value, const int& k) {
        int row = row_value.size(), max_value = INT_MIN;
        for (int top = 0; top < row; top++) {
            int sum = 0;
            for (int bottom = top; bottom < row; bottom++) {
                if(bottom < 0) {
                    sum = 0;
                    continue;
                }
                sum += row_value[bottom];
                if (sum <= k && sum > max_value) max_value = sum;
            }
        }
        return max_value;
    }
};
*/
/*
结合暴力法，采用二分的思想
条件：大面积矩阵-小面积矩阵 <k ==>大面积矩阵 - k < 小面积矩阵

*/
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty()) return 0;
    int row = matrix.size(), col = matrix[0].size(), res = INT_MIN;
    for (int l = 0; l < col; ++l) {
        vector<int> sums(row, 0);
        for (int r = l; r < col; ++r) {
            for (int i = 0; i < row; ++i) {
                sums[i] += matrix[i][r];
            }
            
            // Find the max subarray no more than K 
            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                set<int>::iterator it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
                accuSet.insert(curSum);
            }
            res = std::max(res, curMax);
        }
    }
    return res;
}