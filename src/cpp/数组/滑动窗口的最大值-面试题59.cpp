class Solution {
public:
    int K;
    vector<int> N;
    int window(int idx) {
        int ans = N[idx];
        for (int i = idx-K+1; i <= idx; ++i) {
            ans = max(ans, N[i]);
        }
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        K = k;
        N = nums;
        vector<int> ans;
        int len = nums.size();
        if (len == 0)
            return ans;
        for (int i = k-1; i < len; ++i) {
            ans.push_back(window(i));
        }
        return ans;
    }
};