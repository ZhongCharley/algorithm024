class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int box[9][9] = {0};

        for (int row = 0; row < 9; row ++) {
            for (int col = 0; col < 9; col ++) {
                if (board[row][col] == '.') continue;
                int ch = board[row][col] - '1';
                if (rows[row][ch]) return false;
                if (cols[col][ch]) return false;
                if (box[col / 3 + (row / 3) * 3][ch]) return false;

                rows[row][ch] = 1;
                cols[col][ch] = 1;
                box[col / 3 + (row / 3) * 3][ch] = 1;
            }
        }
        return true;
    }
};
//(row,col)元素所在9宫格，(1, 3) col/ 3 + (row / 3) * 3;