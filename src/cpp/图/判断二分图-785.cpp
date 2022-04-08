class Solution {
public:
    int n;
    vector<int> vis;
    bool ans = true;
    void dfs(vector<vector<int>>& graph, int cur) {
        if (!ans) {
            return ;
        }
        for (auto nxt: graph[cur]) {
            if (nxt < 0 || nxt >= n) {
                continue;
            }
            if (vis[nxt] == 0) {
                vis[nxt] = vis[cur] * -1;
                dfs(graph, nxt);
                if (!ans) {
                    return ;
                }
            } else if (vis[nxt] == vis[cur]){
                ans = false;
                return ;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vis.resize(n);
        if (n == 0) {
            return false;
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                vis[i] = 1;
                dfs(graph, i);
                if (!ans) {
                    return ans;
                }
            }
        }
        return true;
    }
};
