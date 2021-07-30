/*
 * 快排-双指针法
 * 单纯跑一次该函数的时间复杂度是O(n)
 * 剩下的复杂度来源于调用quicksort1和2的次数，取决于pivot的选取
 * */
void quicksort1(vector<int>& nums, int low, int high) {
    if (low > high)
        return;
    int i(low), j(high);
    int pivot = nums[low];
    // 所有的i和j之间的关系都没有=，只考虑跳出循环的情况是i=j
    while (i < j) {
        // 先遍历j
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