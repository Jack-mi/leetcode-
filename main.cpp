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
        int minNumberInRotateArray(vector<int> rotateArray) {
            int l = 0;
            int r = rotateArray.size()-1;
            while (l < r) {
                int mid = (l+r) /2;
                int v = rotateArray[mid];
                if (mid == 0)
                    return v;
                if (v < rotateArray[mid-1])
                    return v;
                else if (v <= rotateArray[rotateArray.size()-1])
                    r = mid-1;
                else
                    l = mid+1;
            }
            return rotateArray[l];
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {3,4,5,1,2};
    cout<<s->minNumberInRotateArray(nums);
    return 0;
}
