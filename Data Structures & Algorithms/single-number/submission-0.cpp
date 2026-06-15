class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Xor operation : 1 XOR 1 = 0
        int res = nums[0];
        int n = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }

        return res;
    }
};
