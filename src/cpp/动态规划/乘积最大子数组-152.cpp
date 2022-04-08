class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
//        vector<int> fmax(len), fmin(len);
//        fmax[0] = fmin[0] = nums[0];
        int ans = nums[0];
        int fmax = nums[0];
        int fmin = nums[0];
        for (int i = 1; i < len; ++i) {
            int tfmax = max(max(fmax*nums[i], fmin*nums[i]), nums[i]);
            int tfmin = min(min(fmax*nums[i], fmin*nums[i]), nums[i]);
            ans = max(ans, max(tfmax, tfmin));
            fmax = tfmax;
            fmin = tfmin;
        }
        return ans;
    }
};
