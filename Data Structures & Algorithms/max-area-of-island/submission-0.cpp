class Solution {
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>>& grid, int r, int c, int &area) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) {
            return;
        }
        area++;
        grid[r][c] = 'V';
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dr[i], c + dc[i], area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
