class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Each row must contain the digits 1-9 without duplicates.
        for (int i = 0; i < 9; ++i) { // row
            unordered_set<int> lineSet;
            for (int j = 0; j < 9; ++j) { // column

                if (board[i][j] == '.') {
                    continue;
                }

                if (lineSet.count(board[i][j])) {
                    return false;
                }


                lineSet.insert(board[i][j]);
            }
        }

        // Each column must contain the digits 1-9 without duplicates.
        for (int i = 0; i < 9; ++i) { // column 
            unordered_set<int> columnSet;
            for (int j = 0; j < 9; ++j) { // row
                if (board[j][i] == '.') {
                    continue;
                }
                if (columnSet.count(board[j][i])) {
                    return false;
                }

                columnSet.insert(board[j][i]);
            }
        }

        // Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
        vector<unordered_set<int>> boxes(9);
        for (int i = 0; i < 81; ++i) {
            int line = floor(i / 9);
            int column = i % 9;
            int box_index = (line / 3) * 3 + (column / 3);

            if (board[line][column] == '.') {
                continue;
            }
            
            if (boxes[box_index].count(board[line][column])) {
                return false;
            }
            
            boxes[box_index].insert(board[line][column]);
        }

        return true;
    }
};
