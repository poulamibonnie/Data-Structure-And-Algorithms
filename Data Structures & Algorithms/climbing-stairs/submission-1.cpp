class Solution {
public:
    int helper(int n, int idx, vector<int> &dp) {
        if (idx > n) {
            return 0;
        }
        if (idx == n) {
            return 1;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }

        return dp[idx] = helper(n, idx + 1, dp) + helper(n, idx + 2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp (n + 1, -1);
        return helper(n, 0, dp);
        
    }
};
