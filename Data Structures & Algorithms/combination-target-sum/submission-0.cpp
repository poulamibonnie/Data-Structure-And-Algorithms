class Solution {
public:
    void helper(vector<int>& nums, int target, int idx, vector<int> &temp, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0 || idx >= nums.size()) {
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, target - nums[i], i, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(nums, target, 0, temp, res);
        return res;
    }
};
