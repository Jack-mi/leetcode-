class Solution {
public:
    int parent[1001];
    int findroot(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool union_root(int x,int y) {
        int rx = findroot(x);
        int ry = findroot(y);
        if (rx == ry)
            return false;
        parent[rx] = ry;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < 1001; ++i) {
            parent[i] = i;
        }
        for (auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            if (!union_root(u, v)) {
                return edge;
            }
        }
        return {};
    }
};