class Solution {
public:
    void helper(vector<int>& candidates,int target, int idx, vector<int> &temp, vector<vector<int>> &res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        if (target < 0 || idx >= candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i == idx || i > idx && candidates[i] != candidates[i - 1]) {
                temp.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, temp, res);
        return res;

    }
};
