class Solution {
public:
    void helper(vector<int>& nums, unordered_set<int> &visited, vector<int> &temp, vector<vector<int>> &res) {
        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(nums[i])) {
                continue;
            }
            temp.push_back(nums[i]);
            visited.insert(nums[i]);
            helper(nums, visited, temp, res);
            visited.erase(nums[i]);
            temp.pop_back();

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> visited;
        vector<int> temp; 
        vector<vector<int>> res;
        helper(nums, visited, temp, res);
        return res;
    }
};
