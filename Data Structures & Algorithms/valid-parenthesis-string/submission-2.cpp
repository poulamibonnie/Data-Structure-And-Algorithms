class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;
         //Minimum and Maximum number of valid open parathesis

        for (char ch : s) {
            if (ch == '(') {
                leftMin++;
                leftMax++;
            }
            else if (ch == ')') {
                leftMin--;
                leftMax--;
            }
            else {
                leftMin--;
                leftMax++;
            }

            if (leftMax < 0) {
                return false;
            }
            if (leftMin < 0) { //Consider case - (*) (
                leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};
