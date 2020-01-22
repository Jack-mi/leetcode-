#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    class Solution {
    public:
        void swap(int& a, int& b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        void maxHeadDown(vector<int>& nums, int start, int end) {
            int cur = start;
            int i = 2*start+1;
            for (; i <= end; cur = i, i = 2*cur+1) {
                if (i < end && nums[i]<nums[i+1])
                    i++;
                if (nums[cur] >= nums[i])
                    break;
                swap(nums[cur], nums[i]);
            }
        }
        void buildHeap(vector<int>& nums) {
            int len = nums.size();
            for (int i = len/2-1; i >= 0; i--)
                maxHeadDown(nums, i, len-1);
        }
        void heapsort(vector<int>& nums) {
            buildHeap(nums);
            for (int i = nums.size()-1; i >= 0; i--) {
                swap(nums[i], nums[0]);
                maxHeadDown(nums, 0, i-1);
            }
        }
        int findKthLargest(vector<int>& nums, int k) {
            if (nums.size() == 1) {
                return nums[0];
            }
            heapsort(nums);
            for (int i = 0; i < nums.size(); ++i) {
                cout<<nums[i]<<" ";
            }
            cout<<endl;
            return nums[nums.size()-k];
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {10,1,-31,26,20,3};
    cout<<s->findKthLargest(nums, 3)<<endl;
    return 0;
}
