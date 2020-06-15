// way-1
class Solution {
public:
    // 快排-双指针法
    void quicksort1(vector<int>& nums, int low, int high) {
        if (low > high)
            return ;
        if (low == high)
            return ;
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
    // 快排-挖坑法
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
        if (nums.size() == 1) {
            return nums[0];
        }
        quicksort(nums, 0, nums.size()-1);
        return nums[nums.size()-k];
    }
};

// way-2
class Solution {
public:
    int flag = 0;
    int ans;
    int len;
    void quicksort(vector<int>& nums, int low, int high, int k) {
        if (low > high) {
            return ;
        }
        if (low == high) {
            flag = 1;
            ans = nums[low];
            return ;
        }
        int i = low;
        int j = high;
        int pivot = nums[low];
        while (i < j) {
            while (i < j && nums[j] >= pivot)
                j--;
            while (i < j && nums[i] <= pivot)
                i++;
            if (i < j) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        nums[low] = nums[i];
        nums[i] = pivot;
        int gap = len-i;
        if (gap== k) {
            flag = 1;
            ans = nums[i];
            return ;
        }
        else if (gap > k) {
            quicksort(nums, i+1, high, k);
            if (flag)
                return ;
        }
        else {
            quicksort(nums, low, i-1, k);
            if (flag)
                return ;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        quicksort(nums, 0, nums.size()-1, k);
        return ans;
    }
};