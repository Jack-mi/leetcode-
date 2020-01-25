void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
/*
 * 从顶start到end构建最大堆
 * 时间复杂度：O(logn)
 * 自上向下的遍历，找到合适的位置放置该节点
 * */
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
/*
 * 初始化堆：给定一个数组，构建最大堆
 * len/2-1为倒数第二行的最后一个节点，即最后一个拥有子节点的节点
 * 时间复杂度：O(n)
 * */
void buildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len/2-1; i >= 0; i--)
        maxHeadDown(nums, i, len-1);
}
/*
 * 给定一个数组，先构建堆，然后实现堆排序
 * 时间复杂度：O(n*logn)
 * */
void heapsort(vector<int>& nums) {
    buildHeap(nums);
    for (int i = nums.size()-1; i >= 0; i--) {
        swap(nums[i], nums[0]);
        maxHeadDown(nums, 0, i-1);
    }
}