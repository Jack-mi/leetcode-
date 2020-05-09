class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        vector<int> count(len);
        for (auto n:nums) {
            count[n]++;
            if(count[n] > 1)
                return n;
        }
        return -1;
    }
};