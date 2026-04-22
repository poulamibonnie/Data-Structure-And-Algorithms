class Solution {
public:
    int helper(vector<int>& nums, int target, int s, int e) {
        if (e < s) {
            return -1;
        }
        int mid = (s + e)/2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && target < nums[mid]) {
                return helper(nums, target, s, mid - 1);
            }
            else {
                return helper(nums, target, mid + 1, e);
            }
        }
        else {
            if (nums[e] >= target && target > nums[mid]) {
                return helper(nums, target, mid + 1, e);
            }
            else {
                return helper(nums, target, s, mid - 1);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
};
