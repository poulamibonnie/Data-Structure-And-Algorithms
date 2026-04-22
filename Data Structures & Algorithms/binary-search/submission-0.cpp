class Solution {
public:
    int helper(vector<int>& nums, int target, int s, int e) {
        if (s > e) {
            return -1;
        }

        int mid = (s + e)/2;

        if (target == nums[mid]) {
            return mid; 
        }
        else if (target < nums[mid]) {
            return helper(nums, target, s, mid - 1);
        }
        else {
            return helper(nums, target, mid + 1, e);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums, target, 0, n - 1);
    }
};
