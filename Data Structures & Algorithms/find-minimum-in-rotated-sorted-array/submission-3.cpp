class Solution {
public:
    int findMin(vector<int> &nums) {
        int s = 0, e = nums.size() - 1;

      
        while (s < e) {
            int mid = (s + e)/2;
            if (nums[e] > nums[mid]) {
                e = mid;
            }
            else {
                s = mid + 1;
            }
        }

        return nums[s];
    }
};
