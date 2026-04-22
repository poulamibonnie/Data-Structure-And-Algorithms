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
        for (int i = n - 1; i > 0; i--) {
            buffer[i] = product * buffer[i - 1];
            product *= nums[i];
        }
        buffer[0] = product;
        return buffer;

    }
};
