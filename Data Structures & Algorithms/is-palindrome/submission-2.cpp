class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            while (!isalpha(s[i]) && !isdigit(s[i])) {
                i++;
            }
            while (!isalpha(s[j]) && !isdigit(s[j])) {
                j--;
            }

            if (i >= j) {
                break;
            }

            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);

            if (s[i] != s[j]) {
                return false;
            }
            else {
                i++; 
                j--;
            }
        }
        return true;
    }
};
