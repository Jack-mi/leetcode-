class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int result = nums[0];
        // dp[i]：以i结尾的子序列最大值
        vector<int> dp(len);
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};