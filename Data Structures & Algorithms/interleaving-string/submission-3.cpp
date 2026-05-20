class Solution {
public:
    int helper(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp) {
        if (i >= s1.size() && j >= s2.size()) {
            return true;
        }
        else if (dp[i][j] != -1) {
            return dp[i][j];
        }
       
        
        int k =  i + j;
        bool ans = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i + 1, j, dp);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            ans = ans || helper(s1, s2, s3, i, j + 1, dp);
        }

        return dp[i][j] = ans;

    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) {
            return false;
        }

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        return helper(s1, s2, s3, 0, 0, dp);
    }
};
