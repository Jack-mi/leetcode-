class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = nums.size();
        int i = 0;
        int j = 0;
        int sum = nums[0];
        if (sum >= target) {
            return 1;
        }
        while(i <= j && j < nums.size()-1) {
            j++;
            if (nums[j] >= target) {
                return 1;
            }
            sum += nums[j];
            if (sum >= target) {
                ans = min(ans, j-i+1);
                for (int k = i; k < j; ++k) {
                    if (sum - nums[k] >= target) {
                        sum -= nums[k];
                        ans = min(ans, j-k);
                    } else {
                        i = k;
                        break;
                    }
                }
            }
        }
        if (sum < target) {
            return 0;
        }
        return ans;
    }
};