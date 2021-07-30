class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int len = nums.size();
        vector<int> dpmax(len), dpmin(len);
        for (int i = 0; i < len; ++i) {
            dpmax[i] = nums[i];
            dpmin[i] = nums[i];
        }
        for (int i = 1; i < len; ++i) {
            dpmax[i] = max(max(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i]), nums[i]);
            dpmin[i] = min(min(dpmax[i-1]*nums[i], dpmin[i-1]*nums[i]), nums[i]);
            ans = max(ans, dpmax[i]);
        }
        return ans;
    }
};
