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
    while (p1 <= mid) {
        tmp[idx++] = nums[p1++];
    }
    while (p2 <= right) {
        tmp[idx++] = nums[p2++];
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