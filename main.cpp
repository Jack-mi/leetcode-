#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
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

    Solution* s = new Solution();
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = s->topKFrequent(nums, k);
    for (int l = 0; l < ans.size(); ++l) {
        cout<<ans[l]<<' ';
    }
    cout<<endl;
    return 0;
}
