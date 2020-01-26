class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int p1(0),p2(0),sum(nums[0]);
        int ans = INT_MAX;
        // 滑动窗口
        while (p1 < nums.size() && p2 < nums.size()) {
            if (sum < s) {
                p2++;
                if (p2 < nums.size())
                    sum += nums[p2];
            } else {
                ans = min(ans, p2-p1+1);
                if (p1 < p2) {
                    sum -= nums[p1];
                    p1++;
                }
                else break;
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};