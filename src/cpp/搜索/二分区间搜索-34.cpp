class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int idx = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] == target) {
                idx = mid;
                break;
            }
            else if (nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        if (idx == -1)
            return {-1,-1};
        int i,j;
        for (i = idx; i >= 0; --i) {
            if (nums[i] != target) {
                i++;
                break;
            }
        }
        // 最后i和j要考虑在边界的情况
        i = i==-1?0:i;
        for (j = idx; j <= nums.size()-1; j++) {
            if (nums[j] != target) {
                j--;
                break;
            }
        }
        j = j==nums.size()?nums.size()-1:j;
        return {i,j};
    }
};