class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return 0;
        }
        vector<int> dp(len);
        dp[0] = 0;
        for (int i = 1; i < len; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < i; ++j) {
                if (nums[j] + j >= i) {
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[len-1];
    }
};
