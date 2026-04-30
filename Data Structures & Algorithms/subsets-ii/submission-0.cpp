class Solution {
public:
    void helper(vector<int>& nums, int idx, vector<int> &temp, vector<vector<int>> &res) {
        if (idx >= nums.size()) {
            res.push_back(temp);
            return;
        }
        res.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            if (i == idx || i > idx && nums[i] != nums[i-1]) {
                temp.push_back(nums[i]);
                helper(nums, i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        helper(nums, 0, temp, res);
        return res;
    }
};
