class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, 0));
        vector<vector<bool>> cols(9, vector<bool>(9, 0));
        vector<vector<bool>> boxes(9, vector<bool>(9, 0));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int c = board[i][j] - '1', boxIndex = i / 3 * 3 + j / 3;
                if (rows[i][c] || cols[j][c] || boxes[boxIndex][c]) return false;
                rows[i][c] = cols[j][c] = boxes[boxIndex][c] = 1;
            }
        }
        return true;
    }
};