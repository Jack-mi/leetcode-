// 快排-双指针法
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