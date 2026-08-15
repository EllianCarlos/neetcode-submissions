class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Each row must contain the digits 1-9 without duplicates.
        vector<unordered_set<int>> boxes(9);
        for (int i = 0; i < 9; ++i) { // row
            unordered_set<int> rowSet;
            unordered_set<int> columnSet;
            for (int j = 0; j < 9; ++j) { // column
                if (rowSet.count(board[i][j])) {
                    return false;
                }
                
                if (columnSet.count(board[j][i])) {
                    return false;
                }

                if (board[i][j] != '.') {
                    rowSet.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    columnSet.insert(board[j][i]);
                }
                
                int box_index = (i / 3) * 3 + (j / 3);

                if (boxes[box_index].count(board[i][j])) {
                    return false;
                }

                if (board[i][j] != '.') {
                    boxes[box_index].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};
