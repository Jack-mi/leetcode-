class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        int dp[len][2];

        // 选了第一个值 得到的dp[len-1][0]和dp[len-1][1]
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = dp[0][0];
        dp[1][1] = nums[1];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        int ans1 = dp[len-1][0];

        // 没选第一个值 得到的dp[len-1][0]和dp[len-1][1]
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for (int i = 1; i < len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        int ans2 = dp[len-1][0];
        int ans3 = dp[len-1][1];
        return max(ans1, max(ans2, ans3));
    }
};