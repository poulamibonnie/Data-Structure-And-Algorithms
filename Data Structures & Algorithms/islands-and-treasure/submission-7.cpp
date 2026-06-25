#define PII pair<pair<int, int>, int>
class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    bool valid(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != INT_MAX) {
            return false;
        }
        return true; 
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        unordered_set<int> visited;
        queue<PII> q;
        int R = grid.size(), C = grid[0].size();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto cell = q.front();
            q.pop();
            int r = cell.first.first;
            int c = cell.first.second;
            int path = cell.second;

            int code = r * C + c;
            if (visited.count(code)) {
                continue;
            }
            visited.insert(code);
            if (grid[r][c] == 2147483647) {
                grid[r][c] = path;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int ncode = nr * C + nc;
                if (valid(grid, nr,  nc) && !visited.count(ncode)) {
                    q.push({{nr,nc}, path + 1});
                }
            }
        }
    }
};
