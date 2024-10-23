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

    int stoi(char x) { return x - '0'; }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rowMap;
        unordered_map<int, unordered_set<int>> colMap;
        unordered_map<int, unordered_set<int>> sqMap;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (presentInHorizontal(rowMap, num, i) ||
                        presentInVertical(colMap, num, j) ||
                        presentInSquare(sqMap, num, i, j))
                        return false;

                    rowMap[i].insert(num);
                    colMap[j].insert(num);
                    sqMap[(i / 3) * 3 + (j / 3)].insert(num);
                }
            }
        }
        return true;
    }
};