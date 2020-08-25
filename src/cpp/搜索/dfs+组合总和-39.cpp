class Solution {
public:
    int tar, len;
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> candi;
    void dfs(int start, int acc) {
        if (acc == tar) {
            ans.push_back(path);
            return ;
        }
        for (int i = start; i < len; ++i) {
            if (candi[i] > tar)
                break;
            if (acc + candi[i] > tar)
                return ;
            path.push_back(candi[i]);
            dfs(i, acc+candi[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candi = candidates;
        len = candidates.size();
        tar = target;
        for (int i = 0; i < len; ++i) {
            if (candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            dfs(i, candidates[i]);
            path.pop_back();
        }
        return ans;
    }
};