class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> um;
        for (int n:nums) um[n]++;
        // 先创建一个大小为n+1的桶，让nums的每一位都能找到对应的下标
        vector<vector<int>> bucket(nums.size()+1);
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            bucket[itr->second].push_back(itr->first);
        }
        // 此时的桶排序就自动通过下标来实现，从后向前遍历
        for (int i = bucket.size()-1; i >= 0; --i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                res.push_back(bucket[i][j]);
                if (--k == 0)
                    return res;
            }
        }
        return res;
    }
};