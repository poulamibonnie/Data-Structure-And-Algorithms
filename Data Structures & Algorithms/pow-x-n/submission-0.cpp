class Solution {
public:
    double helper(double x, int n) {
        if (x == 1 || x == 0) {
            return x;
        }
        else if (n == 0) {
            return 1;
        }
        else if (n == 1) {
            return x;
        }

        double res;
        if (n % 2 == 0) {
            res = helper(x * x, n/2);
        }
        else{
            res = x * helper(x * x, n/2);
        } 
        return res;
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1/helper(x, abs(n));
        }
        else {
            return helper(x, n);
        }
    }
};
