#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    class Solution {
    public:
        using value_t = pair<int, int>;
        struct cmp {
            bool operator() (const value_t& t1, const value_t& t2) {
                return t1.second < t2.second;
            }
        };
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> count;
            for(int n:nums) count[n]++;
            vector<int> res;
            priority_queue<value_t, vector<value_t>, cmp> q;
            for (auto itr = count.begin(); itr != count.end(); itr++) {
                q.push(*itr);
            }
            for (int i = 0; i < k; ++i) {
                auto tmp = q.top();
                q.pop();
                res.push_back(tmp.first);
            }
            return res;
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans;
    string s1 = "pwwkew";
    string s2 = "abc";
    ans = s->topKFrequent(nums, 2);
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}
