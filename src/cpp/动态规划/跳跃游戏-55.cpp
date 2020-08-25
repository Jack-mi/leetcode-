class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return false;
        if (len == 1)
            return true;
        int dp[len];
        dp[0] = nums[0];
        if (dp[0] == 0)
            return false;
        for (int i = 1; i < len-1; ++i) {
            dp[i] = max(dp[i-1], i+nums[i]);
            if (dp[i] == i)
                return false;
        }
        return dp[len - 2] >= len - 1;
    }
};