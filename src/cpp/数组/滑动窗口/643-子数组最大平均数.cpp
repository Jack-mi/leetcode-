// easy
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        int ans = sum;
        for (int i = k; i < nums.size(); ++i) {
            int r = i-k;
            sum -= nums[r];
            sum += nums[i];
            ans = sum>ans?sum:ans;
        }
        return (double)ans/k;
    }
};