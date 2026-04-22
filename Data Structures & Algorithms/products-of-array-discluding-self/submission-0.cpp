class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res, buffer;
        int product = 1;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            product *= nums[i];
            buffer.push_back(product);
        }
        
        product = 1;
        buffer[n - 1] = product * buffer[n - 2];
        for (int i = n - 2; i > 0; i--) {
            product *= nums[i + 1];
            buffer[i] = product * buffer[i - 1];
        }
        product *= nums[1];
        buffer[0] = product;
        return buffer;

    }
};
