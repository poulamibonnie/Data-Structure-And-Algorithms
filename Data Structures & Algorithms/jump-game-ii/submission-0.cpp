class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0;
        int farthest = 0, step = 0, n = nums.size();

        while (farthest < n - 1) {
            for (int i = start; i <= end; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            start = end + 1;
            end = farthest;
            step++;
        }

        return step;
    }
};
