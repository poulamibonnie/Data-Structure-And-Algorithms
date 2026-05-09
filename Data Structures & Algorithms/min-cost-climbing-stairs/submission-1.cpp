class Solution {
public:
    // int helper(vector<int>& cost, int idx, vector<int> &dp) {
    //     if (idx >= cost.size()) {
    //         return 0;
    //     }
    //     if (dp[idx] != -1) {
    //         return dp[idx];
    //     }

    //     return dp[idx] = cost[idx] + min(helper(cost, idx + 1, dp), helper(cost, idx + 2, dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // vector<int> dp(n + 1, -1); for memoization
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return dp[n];
    }
};
