class Solution {
public:
    // 要取余的n为[min,max]中的max
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0)
            return ans;
        for (int i = 0; i < n; ++i) {
            int pos = (nums[i]-1) % n;
            if (nums[pos] > n) {
                // 关键1：要加的值，是和pos相关的
                ans.push_back(pos+1);
                cout<<pos+1<<' ';
            }
            // 关键2：计数，每次出现对应下标位置不是+1，而是+max
            nums[pos] += n;
        }
        cout<<endl;
        return ans;
    }
};