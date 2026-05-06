class Solution {
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    void helper(vector<vector<int>>& heights, int prev, vector<vector<int>> &visited, int r, int c) {
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || prev > heights[r][c] || visited[r][c] == 1 ) {
            return;
        }
        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            helper(heights, heights[r][c], visited, nr, nc);
        }

    }
public:
     
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        vector<vector<int>> res;

        vector<vector<int>> pacific(R, vector<int>(C, 0));
        vector<vector<int>> atlantic(R, vector<int>(C, 0));

        for (int i = 0; i < R; i++) {
            helper(heights, INT_MIN, pacific, i, 0);
            helper(heights, INT_MIN, atlantic, i, C - 1);
        }

        for (int i = 0; i < C; i++) {
            helper(heights, INT_MIN, pacific, 0, i);
            helper(heights, INT_MIN, atlantic, R - 1, i);
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    res.push_back({i,j});
                }
            }
        }


        return res;
    }
};
