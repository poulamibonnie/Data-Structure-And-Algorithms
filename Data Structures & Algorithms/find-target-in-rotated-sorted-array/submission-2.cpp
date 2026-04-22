class Solution {
public:
    int helper(vector<int>& nums, int target, int s, int e) {
        if (s > e) {
            return -1;
        }

        int mid = (s + e)/2;

        if (nums[mid] == target) {
            return mid;
        }
        if (nums[s] <= nums[mid]) {
            if (target >= nums[s] && nums[mid] > target ) {
                return helper(nums, target, s, mid - 1);
            }
            else {
                return helper(nums, target, mid + 1, e);
            }
        }
        else {
            if (target > nums[mid] && nums[e] >= target ) {
                return helper(nums, target, mid + 1, e);
            }
            else {
                return helper(nums, target, s, mid - 1);
            }
        }

    }
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        return helper(nums, target, 0, n);
    }
};
