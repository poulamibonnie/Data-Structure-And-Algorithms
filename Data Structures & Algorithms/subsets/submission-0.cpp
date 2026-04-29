class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int> &temp, vector<vector<int>> &res) {
        if (idx >= nums.size()) {
            res.push_back(temp);
            return;
        }
        res.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, i + 1, temp, res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        helper(nums, 0, temp, res);
        return res;
    }
};
