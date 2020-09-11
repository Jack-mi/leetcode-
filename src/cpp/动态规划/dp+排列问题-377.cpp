class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long > dp(target+1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto step:nums) {
                if (step <= i)
                    dp[i] += dp[i-step];
            }
        }
        return dp[target];
    }
};