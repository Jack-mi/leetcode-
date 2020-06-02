class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int dp[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[len-1][0];
    }
};