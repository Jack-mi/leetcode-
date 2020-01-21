#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    class Solution {
    public:
        void quicksort1(vector<int>& nums, int low, int high) {
            if (low > high)
                return;
            int i(low), j(high);
            int pivot = nums[low];
            while (i < j) {
                while (i < j && nums[j]>=pivot)
                    j--;
                while (i < j && nums[i]<=pivot)
                    i++;
                if (i < j) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
            nums[low] = nums[i];
            nums[i] = pivot;
            quicksort1(nums, low, i-1);
            quicksort1(nums, i+1, high);
        }
        void quicksort(vector<int>& nums, int low, int high) {
            if (low > high)
                return ;
            int i(low), j(high);
            int pivot = nums[low];
            while (i < j) {
                while (i < j && nums[j] >= pivot)
                    j--;
                if (i < j) {
                    nums[i] = nums[j];
                    i++;
                }
                while (i < j && nums[i] <= pivot)
                    i++;
                if (i < j) {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = pivot;
            quicksort(nums, low, i-1);
            quicksort(nums, i+1, high);
        }
        int findKthLargest(vector<int>& nums, int k) {
            int ans = 0;
            quicksort(nums, 0, nums.size()-1);
            for (int j = 0; j < nums.size(); ++j) {
                cout<<nums[j]<<' ';
            }
            cout<<endl;
            if (nums.size() == 1) {
                return nums[0];
            }
            if (k == 1) {
                return nums[nums.size()-1];
            }
            int cnt = 2;
            for (int i = nums.size()-2; i >= 0; --i) {
                if (cnt == k) {
                    ans = nums[i];
                    break;
                }
                int pre = nums[i+1];
                int next = nums[i];
                if (pre != next) {
                    cnt++;
                }
            }
            return ans;
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {3,-2,23,17,22,40,5,5,6};
    cout<<s->findKthLargest(nums, 4)<<endl;
    return 0;
}
