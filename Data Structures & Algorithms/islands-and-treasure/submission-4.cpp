#define PII pair<pair<int, int>,int> 
class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    bool valid(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >=grid[0].size() || grid[r][c] == -1) {
            return false;
        }
        return true;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<PII>q;
        set<long long> visited;
        int cols = grid[0].size();

        //Traverese all chest
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({{i,j}, 0});
                }
            }
        }

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int r = temp.first.first;
            int c = temp.first.second;
            int path = temp.second;
            if (visited.count(r * cols + c)) {
                continue;
            }
            grid[r][c] = path;
            
            visited.insert(r * cols + c);
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (!valid(grid, nr, nc)) {
                    continue;
                }
                q.push({{nr, nc}, path + 1});
            }
        }
        return;
    }
};
