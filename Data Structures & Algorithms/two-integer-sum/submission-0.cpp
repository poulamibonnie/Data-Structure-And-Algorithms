class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        unordered_map<int, int> dict;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (dict.count(target - nums[i])) {
                res[0] = dict[target - nums[i]];
                res[1] = i;
                return res;
            }
            dict[nums[i]] = i;
        }

        return res;
    }
};
