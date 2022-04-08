class Solution {
public:
    vector<int> vis;
    int n;
    void dfs(vector<vector<int>>& isConnected, int x) {
        for (int i = 0; i < n; ++i) {
            if (vis[i] || !isConnected[x][i] || i==x)
                continue;
            vis[i] = 1;
            dfs(isConnected, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vis.resize(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = 1;
            dfs(isConnected, i);
            ans++;
        }
        return ans;
    }
};
