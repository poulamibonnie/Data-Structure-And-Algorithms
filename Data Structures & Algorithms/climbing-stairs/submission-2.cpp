class Solution {
public:
    // int helper(int n, int idx, vector<int> &dp) {
    //     if (idx > n) {
    //         return 0;
    //     }
    //     if (idx == n) {
    //         return 1;
    //     }
    //     if (dp[idx] != -1) {
    //         return dp[idx];
    //     }

    //     return dp[idx] = helper(n, idx + 1, dp) + helper(n, idx + 2, dp);
    // }
    int climbStairs(int n) {
        vector<int> dp (n + 1, 0);
        if (n <= 2) {
            return n;
        }
        dp[1] = 1; 
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
    }
};
