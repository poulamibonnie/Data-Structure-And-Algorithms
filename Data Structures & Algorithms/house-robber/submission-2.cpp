class Solution {
public:
    // int helper(vector<int>& nums, int idx, vector<int> &dp) {
    //     if (idx < 0) {
    //         return 0;
    //     }
    //     if (dp[idx] != -1) {
    //         return dp[idx];
    //     }

    //     return dp[idx] = max(nums[idx] + helper(nums, idx - 2, dp), helper(nums, idx - 1, dp));
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // vector<int> dp(n + 1, -1); memoization
        vector<int> dp(n + 1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i <= n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
