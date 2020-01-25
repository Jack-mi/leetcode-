#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    class Solution {
    public:
        void Merge(vector<int>& nums, int left, int mid, int right) {
            int* tmp = (int*)malloc((right-left+1)* sizeof(int));
            int p1 = left;
            int p2 = mid+1;
            int idx = 0;
            while (p1 <= mid && p2 <= right) {
                if (nums[p1] < nums[p2]) {
                    tmp[idx++] = nums[p1];
                    p1++;
                } else {
                    tmp[idx++] = nums[p2];
                    p2++;
                }
            }
//            while (p1 <= mid) {
//                tmp[idx++] = nums[p1++];
//            }
//            while (p2 <= right) {
//                tmp[idx++] = nums[p2++];
//            }
            if (p1 <= mid) {
                for (int i = p1; i <= mid; i++) {
                    tmp[idx++] = nums[i];
                }
            }
            if (p2 <= right) {
                for (int i = p2; i <= right; ++i) {
                    tmp[idx++] = nums[i];
                }
            }
            for (int i = 0; i < idx; ++i) {
                nums[left+i] = tmp[i];
            }
            free(tmp);
        }
        void MergeSort(vector<int>& nums, int begin, int end) {
            int mid = (begin+end)/2;
            if (end > begin) {
                MergeSort(nums, begin, mid);
                MergeSort(nums, mid+1, end);
                Merge(nums, begin, mid, end);
            }
        }
        int findKthLargest(vector<int>& nums, int k) {
            if (nums.size() == 1) {
                return nums[0];
            }
            MergeSort(nums, 0, nums.size()-1);
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
