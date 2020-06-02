/*
 * way 1 : 当成最大子序列和来做
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 坑1：prices和gap的长度都要判断
        if (prices.size()==0 || prices.size()==1)
            return 0;
        vector<int> gap(prices.size()-1);
        for (int i = 0; i < gap.size(); ++i) {
            gap[i] = prices[i+1]-prices[i];
        }
        int result = gap[0];
        vector<int> dp(gap.size());
        dp[0] = gap[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(gap[i], dp[i-1]+gap[i]);
            result = max(result, dp[i]);
        }
        // 买股票的背景决定这题最后的数字必须是正的
        return result>0?result:0;
    }
};

/*
 * way 2：直接在prices上找到gap最大的price买卖
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int minn = prices[0];
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            ans = max(ans, prices[i]-minn);
            minn = min(minn, prices[i]);
        }
        return ans;
    }
};

/*
 * way 3
 * */
class Solution {
public:
    int INF = -999999;
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0)
            return 0;
        int k = 1;
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