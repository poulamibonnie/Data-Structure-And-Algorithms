class Solution {
public:
    int helper(string &s, int idx, vector<int> &dp) {
        if (idx >= s.size()) {
            return 1;
        }
        else if (s[idx] == '0') {
            return 0;
        }
        else if (dp[idx] != -1) {
            return dp[idx];
        }

        dp[idx] = helper(s, idx + 1, dp);

        if (idx + 1 < s.size()) {
            int dd = 10 * (s[idx] - '0') + (s[idx + 1] - '0');
            if (dd >= 10 && dd <= 26) {
                dp[idx] += helper(s, idx + 2, dp);
            }
        }
        return dp[idx];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(s, 0, dp);
    }
};
