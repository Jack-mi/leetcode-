/*
 * way-1：累加所有的上升段收益
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int cur_min = prices[0];
        int cur_max = prices[0];
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            if (prices[i] >= prices[i-1])
                cur_max = prices[i];
            if (prices[i] < prices[i-1] || i == len-1) {
                ans += (cur_max-cur_min);
                cur_min = cur_max = prices[i];
            }
        }
        return ans;
    }
};

/*
 * way-2：进一步本质化-》将"上升段"的单位缩小到每一天
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            if (prices[i] > prices[i-1])
                ans += prices[i]-prices[i-1];
        }
        return ans;
    }
};

/*
 * way-3:general solution
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        // 第2个维度是当天是否持有该股票
        int dp[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[len-1][0];
    }
};