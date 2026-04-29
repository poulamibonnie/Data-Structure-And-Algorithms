class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
public:
    void dfs (vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1') {
            return;
        }
        grid[r][c] = 'V';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dr[i], c + dc[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int totalIsland = 0;
        int R = grid.size(), C = grid[0].size();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    totalIsland++;
                }
            }
        }

        return totalIsland;

    }
};
