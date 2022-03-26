class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.push({nums[i], i});
        }
        vector<int> ans;
        ans.push_back(q.top().first);
        // right pointer traversal
        for (int i = k; i < nums.size(); ++i) {
            q.push({nums[i], i});
            while (q.top().second <= i-k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};