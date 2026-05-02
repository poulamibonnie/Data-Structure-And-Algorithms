#define PII pair<int,int>
class Solution {
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
public:
    bool isValid(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_set<int> visited;
        int R = grid.size(), C = grid[0].size();
        int time = -1;
        queue<PII> q;
        int fresh = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }
        //cout<<fresh<<endl;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto temp = q.front();
                q.pop();
                int r = temp.first;
                int c = temp.second;
                int node_code = r * C + c;
                if (visited.count(node_code)) {
                    continue;
                }
                visited.insert(node_code);
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (!isValid(grid, nr, nc)) {
                        continue;
                    }
                    q.push({nr,nc});
                    grid[nr][nc] = 2;
                    fresh--;
                }
            }
            time++;
        }
        //cout<<fresh<<endl;
        return (fresh == 0) ? time : -1;

    }
};
