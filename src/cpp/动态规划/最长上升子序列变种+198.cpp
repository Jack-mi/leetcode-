class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        int result = 0;
        // key1:result和dp数组的初始化
        for (int i = 0; i < nums.size(); ++i) {
            result = max(nums[0], nums[1]);
            dp[i] = nums[i];
        }
        // key2:dp的状态转移，本质和最长上升子序列一样
        for (int i = 2; i < nums.size(); ++i) {
            for (int j = 0; j < i-1; ++j) {
                dp[i] = max(dp[j] + nums[i], dp[i]);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};