class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len, 1);
        vector<int> record(len,1);
        map<int, int> cnt;
        int ans = 0;
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j])
                    continue;
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
            int cc = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] <= nums[j])
                    continue;
                if (dp[i] == dp[j]+1) {
                    cc += record[j];
                    cnt[dp[i]] += record[j];
                }
            }
            record[i] = cc==0?1:cc;
        }
//        for (auto x:cnt)
//            cout<<x.first<<':'<<x.second<<endl;
        if (ans == 0)
            return nums.size();
        return cnt[ans];
    }
};