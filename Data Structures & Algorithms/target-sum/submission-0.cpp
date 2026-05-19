class Solution {
public:
    int helper(vector<int>& nums, int target, int idx, map<pair<int,int>, int> &dp) {
        if (dp.count({idx,target})) {
            return dp[{idx,target}];
        }
        if (idx >= nums.size()) {
            if (target == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }

        return dp[{idx,target}] = helper(nums, target - nums[idx], idx + 1, dp) +
                                 helper(nums, target + nums[idx], idx + 1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int> dp;
        return helper(nums, target, 0, dp);
    }
};
