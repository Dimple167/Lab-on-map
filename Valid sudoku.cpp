    class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0}, cols[9][9] = {0}, boxes[9][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';  // Convert '1'-'9' to 0-8
                    int boxIndex = (r / 3) * 3 + (c / 3);

                    if (rows[r][num] || cols[c][num] || boxes[boxIndex][num]) {
                        return false;  // Duplicate found
                    }

                    rows[r][num] = cols[c][num] = boxes[boxIndex][num] = 1;
                }
            }
        }
        
        return true;
    }
};
