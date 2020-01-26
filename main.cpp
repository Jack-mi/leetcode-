#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    class Solution {
    public:
        // 要取余的数为[min,max]中的max
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> ans;
            int n = nums.size();
            if (n == 0)
                return ans;
            for (int i = 0; i < n; ++i) {
                int pos = (nums[i]-1) % n;
                nums[pos] += n;
            }
            for (int j = 0; j < n; ++j) {
                if (nums[j] > 2*n)
                    ans.push_back(j+1);
            }
            return ans;
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {4,3,2,7,8,2,3,1};
    s->findDuplicates(nums);
    return 0;
}
