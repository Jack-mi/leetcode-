class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int s = -1;
        int e = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]%2 != 0) {
                if (s == -1)
                    continue;
                else {
                    int t = nums[i];
                    nums[i] = nums[s];
                    nums[s] = t;
                    s++;
                    e++;
                }
            } else {
                if (s == -1) {
                    s = e = i;
                } else {
                    e++;
                }
            }
        }
        return nums;
    }
};