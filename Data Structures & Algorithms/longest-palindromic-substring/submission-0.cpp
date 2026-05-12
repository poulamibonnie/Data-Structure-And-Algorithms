class Solution {
public:
    void helper(string &s, int i, int j, string &res) {
        if (res.size() < (j - i + 1)) {
            res = s.substr(i, j - i + 1);
        }

        return;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        string rev = s;
        reverse(rev.begin(), rev.end());

        if (s == rev) {
            return s;
        }

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    helper(s, i, j, res);
                }
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        helper(s, i, j, res);
                    }
                    else {
                        dp[i][j] = 0;
                        
                    }
                }
            }
        } 

        for (int i = n - 3; i >= 0; i--) {
            for (int j = n - 1; j >= i + 2; j--) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    helper(s, i, j, res);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return res;
    }
};
