class Solution {
public:
    /*
     * 注意审题，只会出现重复两次的情况
     * 关键：对不在"等同数组下标位置"且"目标位置的值等于自身"的情况
     * */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i < nums.size();i++) {
            while(i < nums.size() && nums[i] != i+1) {
                if(nums[i] == nums[nums[i]-1]) {
                    i++;
                    continue;
                }
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != i+1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};