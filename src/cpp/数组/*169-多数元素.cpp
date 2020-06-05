// way1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int ans;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            count[cur]++;
            if (count[cur] > nums.size()/2)
                ans = cur;
        }
        return ans;
    }
};

// way2
/*
 * （1）当num为0时，candidate肯定在右边
 * （2）当被抵消的candidate是众数时，右边的众数依然是最终的众数
 * （3）当被抵消的candidate不是众数是，那右边的众数就更是众数了
 * */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int num = 0;
        for (auto cur: nums) {
            if (cur == candidate)
                num++;
            else {
                if (--num < 0) {
                    candidate = cur;
                    num = 0;
                }
            }
        }
        return candidate;
    }
};