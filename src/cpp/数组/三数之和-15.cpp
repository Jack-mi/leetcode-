class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        // 特判：数组个数不足3个
        if (len < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int n1 = 0; n1 < len-2; ++n1) {
            // 后面的数都为正
            if (nums[n1] > 0)
                break;
            // 跟上一个数一样
            if (n1>0 && nums[n1]==nums[n1-1])
                continue;

            int n2 = n1 + 1;
            int n3 = len - 1;
            int target = -nums[n1];

            // 双指针遍历
            while (n2 < n3) {
                if (nums[n2] + nums[n3] == target) {
                    ans.push_back(vector<int> {nums[n1], nums[n2], nums[n3]});
                    n2++;
                    n3--;
                    // 关键：去重
                    while (n2<n3 && nums[n2]==nums[n2-1]) n2++;
                    while (n2<n3 && nums[n3]==nums[n3+1]) n3--;
                } // 不相等的情况不需要判重，因为此时即使重复后面也不会进入push_back的分支
                else if (nums[n2] + nums[n3] > target) {
                    n3--;
                } else {
                    n2++;
                }
            }
        }
        return ans;
    }
};