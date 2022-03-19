class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0)
            return false;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                s.erase(nums[i-k-1]);
            }
            if (s.count(nums[i]) > 0) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};