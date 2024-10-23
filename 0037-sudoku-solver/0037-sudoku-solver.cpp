class Solution {
public:
    bool presentInHorizontal(unordered_map<int, unordered_set<int>>& rowMap,
                             int num, int row) {
        return rowMap[row].find(num) != rowMap[row].end();
    }
    bool presentInVertical(unordered_map<int, unordered_set<int>>& colMap,
                           int num, int col) {
        return colMap[col].find(num) != colMap[col].end();
    }
    bool presentInSquare(unordered_map<int, unordered_set<int>>& sqMap, int num,
                         int row, int col) {
        return sqMap[(row / 3) * 3 + (col / 3)].find(num) !=
               sqMap[(row / 3) * 3 + (col / 3)].end();
    }
    bool helper(vector<vector<char>>& board, int row, int col,
                unordered_map<int, unordered_set<int>>& rowMap,
                unordered_map<int, unordered_set<int>>& colMap,
                unordered_map<int, unordered_set<int>>& sqMap) {

        if (row == 9)
            return true;

        if (board[row][col] == '.') {
            for (int i = 1; i < 10; i++) {
                if (!presentInHorizontal(rowMap, i, row) &&
                    !presentInVertical(colMap, i, col) &&
                    !presentInSquare(sqMap, i, row, col)) {

                    rowMap[row].insert(i);
                    colMap[col].insert(i);
                    sqMap[(row / 3) * 3 + (col / 3)].insert(i);
                    board[row][col] = i + '0';

                    if (col == 8) {
                        if (helper(board, row + 1, 0, rowMap, colMap, sqMap))
                            return true;
                    } else {
                        if (helper(board, row , col + 1, rowMap, colMap, sqMap))
                            return true;
                    }
                    board[row][col] = '.';
                    rowMap[row].erase(i);
                    colMap[col].erase(i);
                    sqMap[(row / 3) * 3 + (col / 3)].erase(i);
                }
            }
        } else {
            if (col == 8) {
                if (helper(board, row + 1, 0, rowMap, colMap, sqMap))
                    return true;
            } else {
                if (helper(board, row , col + 1, rowMap, colMap, sqMap))
                    return true;
            }
        }
        return false;
    }

    int stoi(char x) { return x - '0'; }

    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rowMap;
        unordered_map<int, unordered_set<int>> colMap;
        unordered_map<int, unordered_set<int>> sqMap;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = stoi(board[i][j]);
                    rowMap[i].insert(num);
                    colMap[j].insert(num);
                    sqMap[(i / 3) * 3 + (j / 3)].insert(num);
                }
            }
        }

        helper(board, 0, 0, rowMap, colMap, sqMap);
    }
};