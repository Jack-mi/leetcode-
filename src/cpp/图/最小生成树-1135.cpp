class Solution {
public:
    struct cmp {
        bool operator() (vector<int>& a, vector<int>& b) {
            return a[2]<b[2];
        }
    };
    int parent[10001];
    int find_root(int x) {
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    void union_root(int x, int y) {
        int rx = find_root(x);
        int ry = find_root(y);
        parent[rx] = ry;
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        // kruskal算法
        sort(connections.begin(), connections.end(), cmp());
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
        int ans = 0;
        for (auto edge:connections) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int ru = find_root(u);
            int rv = find_root(v);
            if (ru == rv)
                continue;
            union_root(ru, rv);
            ans += w;
        }
        // 判断图的连通性
        for (int i = 2; i <= N; ++i) {
            if (find_root(i) != find_root(i-1))
                return -1;
        }
        return ans;
    }
};