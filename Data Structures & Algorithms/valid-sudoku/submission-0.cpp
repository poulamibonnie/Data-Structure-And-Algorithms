class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], box[3][3];
        int R = board.size(), C = board[0].size();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                char elm = board[i][j];
                if (rows[i].count(elm) || cols[j].count(elm) || box[i/3][j/3].count(elm)) {
                    return false;
                }
                rows[i].insert(elm);
                cols[j].insert(elm);
                box[i/3][j/3].insert(elm);
            }
        }
        return true;
    }
};
