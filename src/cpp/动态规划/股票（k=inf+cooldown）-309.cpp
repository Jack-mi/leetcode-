class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int INF = -999999;
        int len = prices.size();
        if (len == 0)
            return 0;
        // dim2-whether to hold a stock today
        // dim3-whether to make a deal today
        int dp[len][2][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = INF;

        dp[0][1][0] = -prices[0];
        dp[0][1][1] = INF;
        for (int i = 1; i < len; ++i) {
            dp[i][0][0] = max(dp[i-1][0][0],dp[i-1][0][1]);
            dp[i][0][1] = max(dp[i-1][1][0],dp[i-1][1][1]) + prices[i];

            dp[i][1][0] = max(dp[i-1][1][1], dp[i-1][1][0]);
            dp[i][1][1] = dp[i-1][0][0]-prices[i];
        }
        return max(dp[len-1][0][0], dp[len-1][0][1]);
    }
};