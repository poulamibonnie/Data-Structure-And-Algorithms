class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (res.empty() || res.back() < nums[i]) {
                res.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
                res[idx] = nums[i];
            }
        }
        return res.size();
    }
};
