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
        vector<vector<int>> dp(n + 2, vector<int> (3, 0));

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[idx][buy] = max(-prices[idx] + dp[idx + 1][0],
                    dp[idx + 1][1]);
                }
                else {
                    dp[idx][buy] = max(prices[idx] + dp[idx + 2][1],
                    dp[idx + 1][0]);
                }  
            }
        }
        return dp[0][1];
    }
};
