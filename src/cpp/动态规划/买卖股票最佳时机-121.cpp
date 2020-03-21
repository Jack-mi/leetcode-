class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
        return result>0?result:0;
    }
};