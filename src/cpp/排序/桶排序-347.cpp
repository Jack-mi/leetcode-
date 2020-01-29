class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> um;
        for (int n:nums) um[n]++;
        vector<vector<int>> bucket(nums.size()+1);
        for (auto itr = um.begin(); itr != um.end(); itr++) {
            bucket[itr->second].push_back(itr->first);
        }
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