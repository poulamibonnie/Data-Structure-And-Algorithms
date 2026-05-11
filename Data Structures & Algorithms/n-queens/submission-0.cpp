class Solution {
    bool isValid(vector<string> &board, int r, int c) {
        int n = board.size();
        int R = r, C = c;

        // diagonal up
        while(r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;

        }

        r = R, c = C;

        // horizontal back
        while(c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            c--;
        }

        r = R, c = C;
        // diagonal down
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            c--;
            r++;
        }
        return true;
    }
public:
    void helper(vector<string> &board, vector<vector<string>> &res, int c) {
        if (c == board.size()) {
            res.push_back(board);
            return;
        }
        
        for (int r = 0; r < board.size(); r++) {
            if (isValid(board, r, c)) {
                board[r][c] = 'Q';
                helper(board, res, c + 1);
                board[r][c] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<string> board(n);
        string s(n,'.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        helper(board, res, 0);

        return res;
    }
};
