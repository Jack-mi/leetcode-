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
    int INF = 0x7fffff;
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int len = prices.size();
        if (len == 0)
            return ans;
        // 2d: 是否持有
        // 3d: sell次数
        int dp[len][2][2];
        dp[0][0][0] = 0;
        dp[0][0][1] = -INF;
        dp[0][1][0] = -prices[0];
        dp[0][1][1] = -INF;
        for (int i = 1; i < len; ++i) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][0]+prices[i]);
            dp[i][1][0] = max(dp[i-1][0][0]-prices[i], dp[i-1][1][0]);
        }
        return max(dp[len-1][0][1], 0);
    }
};