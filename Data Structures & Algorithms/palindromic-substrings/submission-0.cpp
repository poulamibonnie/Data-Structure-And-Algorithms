class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    res++;
                }
                else if (j == i + 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        res++;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        for (int i = n - 3; i >= 0; i--) {
            for (int j = n - 1; j >= i + 2; j--) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    res++;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return res;
    }
};
