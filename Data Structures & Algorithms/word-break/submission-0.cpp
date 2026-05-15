class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());


        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                string str = s.substr(j, i - j + 1);
                if (dict.count(str) && (dp[j - 1] == true || j == 0)) {
                    dp[i] = true;
                }
            }
        }
        return dp[n-1];
    }
};
