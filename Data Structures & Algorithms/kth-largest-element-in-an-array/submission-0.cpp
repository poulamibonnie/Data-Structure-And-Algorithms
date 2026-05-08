class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> left, right, mid;
        int n = nums.size();

        int pivot = nums[rand() % n];

        for (int num : nums) {
            if (num > pivot) {
                left.push_back(num);
            } 
            else if (num < pivot) {
                right.push_back(num);
            }
            else {
                mid.push_back(num);
            }
        }

        if (left.size() >= k) {
            return findKthLargest(left, k);
        }
        else if (left.size() + mid.size() < k) {
            return findKthLargest(right, k - (left.size() + mid.size()));
        }
        else {
            return pivot;
        }
    }
};
