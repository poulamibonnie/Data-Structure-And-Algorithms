class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        reverse(digits.begin(), digits.end());
        int sum = digits[0] + 1;
        int carry = sum/10;
        int num = sum%10;
        res.push_back(num);

        for (int i = 1; i < digits.size(); i++) {
            sum = digits[i] + carry;
            carry = sum/10;
            num = sum%10;
            res.push_back(num);
        }
        if (carry) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
