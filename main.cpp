#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    class Solution {
    public:
        vector<int> maxInWindows(const vector<int>& num, unsigned int size)
        {

        }
    };

    Solution* s = new Solution();
    vector<int> nums = {2,3,4,2,6,2,5,1};
    vector<int> ans = s->maxInWindows(nums, 3);
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<' ';
    }
    return 0;
}
