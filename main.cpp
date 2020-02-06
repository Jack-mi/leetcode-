#include <iostream>
#include <vector>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size()-1;
            int idx = -1;
            while (l <= r) {
                int mid = (l+r)/2;
                if (nums[mid] == target) {
                    idx = mid;
                    break;
                }
                else if (nums[mid] < target) l = mid+1;
                else r = mid-1;
            }
            if (idx == -1)
                return {-1,-1};
            int i,j;
            for (i = idx; i >= 0; --i) {
                if (nums[i] != target) {
                    i++;
                    break;
                }
            }
            i = i==-1?0:i;
            for (j = idx; j <= nums.size()-1; j++) {
                if (nums[j] != target) {
                    j--;
                    break;
                }
            }
            j = j==nums.size()?nums.size()-1:j;
            return {i,j};
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {1};
    int target = 1;
    s->searchRange(nums, target);
    return 0;
}
