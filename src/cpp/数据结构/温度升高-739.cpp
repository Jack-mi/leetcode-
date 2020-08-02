class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> higher;
        higher.push(0);
        vector<int> ans(T.size());
        for (int i = 1; i < T.size(); ++i) {
            int cur = T[i];
            while (!higher.empty()) {
                int idx = higher.top();
                if (T[idx] >= cur)
                    break;
                ans[idx] = i-idx;
                higher.pop();
            }
            higher.push(i);
        }
        return ans;
    }
};