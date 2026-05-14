class Solution {
    bool isValid(vector<string> &board, int r, int c) {
        int row = r, col = c, n = board.size();

        // check left-up diagonal
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        // Horizonal backward
        r = row, c = col;
        while (c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            c--;
        }

        // check left-down diagonal
        r = row, c = col;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r++;
            c--;
        }
        return true;
    }

    void helper(vector<string> &board, int c, vector<vector<string>> &res) {
        if (board.size() == c) {
            res.push_back(board);
            return;
        }

        for (int r = 0; r < board.size(); r++) {
            if (isValid(board, r, c)) {
                board[r][c] = 'Q';
                helper(board, c + 1, res);
                board[r][c] = '.';
            }
        }
    }

    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        helper(board, 0, res);
        return res;
    }
};
