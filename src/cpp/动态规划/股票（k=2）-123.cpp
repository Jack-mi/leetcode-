class Solution {
public:
    int INF = -999999;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        // 第二个维度是当天是否持股
        // 第三个维度是至今已经卖了几次股票
        int dp[len][2][3];
        dp[0][0][0] = 0;

        dp[0][0][1] = INF;
        dp[0][0][2] = INF;

        dp[0][1][0] = -prices[0];
        dp[0][1][1] = INF;
        for (int i = 1; i < len; ++i) {
            dp[i][0][0] = 0;

            dp[i][0][1] = max(dp[i-1][1][0]+prices[i], dp[i-1][0][1]);
            dp[i][0][2] = max(dp[i-1][1][1]+prices[i], dp[i-1][0][2]);

            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][0]-prices[i]);
            dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][1]-prices[i]);
        }
        return max(dp[len-1][0][2], max(dp[len-1][0][1], 0));
    }
};