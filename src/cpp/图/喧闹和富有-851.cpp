class Solution {
public:
    vector<int> ans;
    int n;
    vector<vector<int>> g;
    void dfs(vector<int>& quiet, int x) {
        if (ans[x] != -1) {
            return ;
        }
        ans[x] = x;
        for (int nxt : g[x]) {
            dfs(quiet, nxt);
            if (quiet[ans[nxt]] < quiet[ans[x]]) {
                ans[x] = ans[nxt];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();
        if (n == 1) {
            return {quiet[0]};
        }
        ans.resize(n, -1);
        g.resize(n);
        for (auto p: richer) {
            int big = p[0];
            int small = p[1];
            g[small].push_back(big);
        }
        for (int i = 0; i < n; i++) {
            dfs(quiet, i);
        }
        return ans;
    }
};
