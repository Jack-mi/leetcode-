class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // 当n=0时特殊处理
        if (n == 0)
            return 1;
        // 统计是否存在zero
        int zeroExist = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zeroExist = 1;
            }
        }
        // 记录0～n-1之外最小的数
        // 最关键点：并将所有不在0～n-1之间的数设为0
        int bigThanN = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > n-1) {
                bigThanN = nums[i]<bigThanN?nums[i]:bigThanN;
                nums[i] = 0;
            }
            if (nums[i] < 0)
                nums[i] = 0;
        }
        // 原地计数排序
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                int pos = nums[i] % n;
                nums[pos] += n;
            }
        }
        int ans = -1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < n) {
                ans = i;
                break;
            }
        }
        // 如果在1～n-1之间没有找到，则答案可能是n或n+1
        if (ans == -1) {
            if (zeroExist) {
                ans = n;
            }else {
                if (bigThanN > n)
                    ans = n;
                else
                    ans = n+1;
            }
        }
        return ans;
    }
};