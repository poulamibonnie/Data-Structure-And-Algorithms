class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prod * nums[i];
            prod *= nums[i];
        }
        prod = 1;

        for (int i = nums.size() - 1; i >= 1; i--) {
            res[i] = res[i - 1] * prod;
            prod *= nums[i];
        }
        res[0] = prod;
        return res;
    }
};
