class Solution {
public:
    int helper(vector<int>& prices, int idx, bool buy, vector<vector<int>> &dp) {
        if (idx >= prices.size()) {
            return 0;
        }
        else if (dp[idx][buy] != -1) {
            return dp[idx][buy];
        }

        if (buy) {
            dp[idx][buy] = max(-prices[idx] + helper(prices, idx + 1, false, dp),
            helper(prices, idx + 1, true, dp));
        }
        else {
            dp[idx][buy] = max(prices[idx] + helper(prices, idx + 2, true, dp),
            helper(prices, idx + 1, false, dp));
        }  

        return  dp[idx][buy] ;   

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (3, -1));
        return helper(prices, 0, true, dp);
    }
};
