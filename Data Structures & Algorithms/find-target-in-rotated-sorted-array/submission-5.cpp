class Solution {
    int helper(vector<int>& nums, int target, int s, int e) {
        if (s > e) {
            return -1;
        }

        int mid = (s + e)/2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && nums[mid] > target) {
                return helper(nums, target, s, mid - 1);
            }
            else {
                return helper(nums, target, mid + 1,  e);
            }
        }
        else {
            if (nums[mid] < target && nums[e] >= target) {
                return helper(nums, target, mid + 1,  e);
            }
            else {
                return helper(nums, target, s, mid - 1);
            }
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        return helper(nums, target, s, e);
    }
};
