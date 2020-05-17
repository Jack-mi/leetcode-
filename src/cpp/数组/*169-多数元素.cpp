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
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
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