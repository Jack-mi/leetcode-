class Solution {
public:
    // Equivalent to finding the longest subarray which contains k 0s.
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) sum++;
            while (sum > k) {
                if (nums[l] == 0) sum--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};