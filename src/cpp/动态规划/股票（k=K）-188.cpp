class Solution {
public:
    int INF = -999999;
    // 当k>len/2的时候，相当于k=inf
    int maxprofit(vector<int>& prices) {
        int len = prices.size();
        int dp[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[len-1][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        if (k > len/2) {
            return maxprofit(prices);
        }
        int dp[len][k+1][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = -prices[0];
        for (int i = 1; i <= k; ++i) {
            dp[0][i][0] = INF;
            dp[0][i][1] = INF;
        }
        for (int i = 1; i < len; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0]-prices[i]);
            for (int j = 1; j <= k; ++j) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0]-prices[i]);
            }
        }
        int ans = INF;
        for (int i = 0; i <= k; ++i) {
            ans = max(ans, dp[len-1][i][0]);
        }
        return ans;
    }
};