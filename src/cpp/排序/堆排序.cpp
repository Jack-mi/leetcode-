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
void heapDown(vector<int>& nums, int start, int end) {
    int cur = start;
    int i = 2*start+1; // root从零开始计数的左字节点
    for (; i <= end; cur = i, i = 2*cur+1) {
        // 找出两个字节点中更大的那一个
        if (i < end && nums[i]<nums[i+1])
            i++;
        if (nums[cur] >= nums[i])
            break;
        swap(nums[cur], nums[i]);
    }
}
/*
 * 初始化堆：给定一个数组，构建最大堆
 * len/2-1为倒数第二行的一个节点，即最后一个拥有孩子节点的节点
 * 时间复杂度：O(n)
 * */
void buildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len/2-1; i >= 0; i--)
        heapDown(nums, i, len-1);
}
/*
 * 堆是一个完全二叉树
 * 给定一个数组，先构建堆，然后实现堆排序
 * 时间复杂度：O(n*logn)
 * */
void heapsort(vector<int>& nums) {
    // 1.初始化堆
    buildHeap(nums);
    // 2.堆排序
    for (int i = nums.size()-1; i >= 0; i--) {
        swap(nums[i], nums[0]);
        heapDown(nums, 0, i-1);
    }
}