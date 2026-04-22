class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (store.count(nums[i])) {
                return true;
            }
            store.insert(nums[i]);
        }
        return false;
    }
};