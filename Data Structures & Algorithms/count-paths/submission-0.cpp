class Solution {
public:
    int dfs(int m, int n, int r, int c, vector<vector<int>> &dp) {
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return 0;
        }
        else if (r == m - 1 && c == n - 1) {
            return 1;
        }
        else if (dp[r][c] != -1) {
            return dp[r][c];
        }

        return dp[r][c] = dfs(m, n, r + 1, c, dp) + dfs(m, n, r, c + 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return dfs(m, n, 0, 0, dp);
    }
};
