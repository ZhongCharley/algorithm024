class Solution {
private:
unordered_set<int> pie, cols, na;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        dfs(ans, 0, cur);
        return ans;
    }

    void dfs(vector<vector<string>>& ans, int row, vector<string>& cur) {
        if (row >= cur.size()) {
            ans.push_back(cur);
            return;
        }

        for (int col = 0; col < cur.size(); col++) {
            if (pie.find(row + col) != pie.end() || na.find(row - col) != na.end() || cols.find(col) != cols.end()) continue;

            cur[row][col] = 'Q';
            pie.insert(row + col);
            na.insert(row - col);
            cols.insert(col);

            dfs(ans, row + 1, cur);

            pie.erase(row + col);
            na.erase(row - col);
            cols.erase(col);
            cur[row][col] = '.';
        }
        return;
    }
};