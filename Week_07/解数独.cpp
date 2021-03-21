class Solution {
private:
vector<vector<int>> rows = vector<vector<int>>(9, vector<int>(9,0));
vector<vector<int>> cols = vector<vector<int>>(9, vector<int>(9,0));
vector<vector<int>> box  = vector<vector<int>>(9, vector<int>(9,0));
bool backtracking(vector<vector<char>>& board) {
    for (int row = 0; row < board.size(); row++) {        // 遍历行
        for (int col = 0; col < board[0].size(); col++) { // 遍历列
            if (board[row][col] != '.') continue;
            for (char k = '1'; k <= '9'; k++) {     // (row, col) 这个位置放k是否合适
                if (isValid(row, col, k)) { 
                    board[row][col] = k;                // 放置k
                    int ch = k - '1';
                    rows[row][ch] = 1;
                    cols[col][ch] = 1;
                    box[col / 3 + (row / 3) * 3][ch] = 1;

                    if (backtracking(board)) return true; // 如果找到合适一组立刻返回

                    rows[row][ch] = 0;
                    cols[col][ch] = 0;
                    box[col / 3 + (row / 3) * 3][ch] = 0;                    
                    board[row][col] = '.';              // 回溯，撤销k
                }
            }
            return false;                           // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}
bool isValid(int row, int col, char val) {
    int ch = val - '1';
    if (rows[row][ch]) return false;
    if (cols[col][ch]) return false;
    if (box[col / 3 + (row / 3) * 3][ch]) return false;
    return true;
}
void Init_value(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row ++) {
        for (int col = 0; col < 9; col ++) {
            if (board[row][col] == '.') continue;
            int ch = board[row][col] - '1';
            rows[row][ch] = 1;
            cols[col][ch] = 1;
            box[col / 3 + (row / 3) * 3][ch] = 1;
        }
    }
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        Init_value(board);
        backtracking(board);
    }
};