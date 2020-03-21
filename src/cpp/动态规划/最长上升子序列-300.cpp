class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
        int result = -1;
        int len = nums.size();
        vector<int> dp(len, 1);
        // dp[i] = dp[j]+1, j为0-i之间dp最大的值
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};