class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 'O'){
            return;
        } 
        grid[r][c] = 'V';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dr[i], c + dc[i]);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int R = board.size(), C = board[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == R - 1 || j == C - 1)) {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
