// 当数组的值不在n的范围内，用map来做hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        for (int k = 0; k < nums.size(); ++k) {
            int v = nums[k];
            int res = target-v;
            if (dic.find(res) != dic.end())
                return {k, dic[res]};
            dic[v] = k;
        }
        return {-1, -1};
    }
};