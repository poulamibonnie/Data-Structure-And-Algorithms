class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
public:
    bool helper(vector<vector<char>>& board, string &word, int idx, int r, int c) {
        if (idx >= word.size()) {
            return true;
        }
        if ( r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        board[r][c] = '#';
        bool ans = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            ans |= helper(board, word, idx + 1, nr, nc); 
        }
        board[r][c] = word[idx];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size(), C = board[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (helper(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
