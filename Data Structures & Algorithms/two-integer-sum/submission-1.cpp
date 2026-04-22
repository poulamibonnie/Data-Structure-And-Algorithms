class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        int i = 0;
        for (int num : nums) {
            if (store.count(target - num)) {
                return {store[target - num], i};
            }
            store[num] = i;
            i++;
        }
        return {-1, -1};
    }
};
