class Solution {
public:
    vector<int> vis;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& path) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return ;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i])
                continue;
            vis[i] = 1;
            path.push_back(nums[i]);
            dfs(nums, path);
            vis[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return ans;
        for (int i = 0; i < len; ++i) {
            vector<int> cur(len);
            vis = cur;
            vis[i] = 1;

            vector<int> path;
            path.push_back(nums[i]);

            dfs(nums, path);
        }
        return ans;
    }
};