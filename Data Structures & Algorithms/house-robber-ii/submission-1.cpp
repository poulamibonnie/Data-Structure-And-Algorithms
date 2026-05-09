class Solution {
public:
    int helper(vector<int>& nums, int idx, int end, vector<int> &dp) {
        if (idx > end) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        return dp[idx] = max(nums[idx] + helper(nums, idx + 2, end, dp), helper(nums, idx + 1, end, dp));


    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
        return max(helper(nums, 0, n - 2, dp1), helper(nums, 1, n - 1, dp2));
    }
};
