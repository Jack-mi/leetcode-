class Solution {
public:
    /*
     * 注意审题，只会出现重复两次的情况
     * 关键：对不在"等同数组下标位置"且"目标位置的值等于自身"的情况
     * */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int i = 0;
        while (i < nums.size()) {
            while(i < nums.size() && nums[i] != i+1) {
                // 元素nums[i]的对等坐标，判断元素值是否等于"对等坐标值"
                int pos = nums[i]-1;
                if(nums[i] == nums[pos]) {
                    i++;
                    continue;
                }
                // 让元素nums[i]交换到自己对等下标的位置
                swap(nums[i], nums[pos]);
            }
            i++;
        }
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};