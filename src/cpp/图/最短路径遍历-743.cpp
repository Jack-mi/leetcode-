class Solution {
public:
    int Node = 105;
    int INF = 0x7fffff;
    int G[105][105];
    int v, minn;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int ans = -1;
        vector<int> s(105, 0);
        vector<int> dis(105);
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                G[i][j] = i==j?0:INF;
            }
        }
        for (auto list : times) {
            int source(list[0]), d(list[1]), w(list[2]);
            G[source][d] = w;
        }
        s[K] = 1;
        for (int i = 1; i <= N; ++i) {
            dis[i] = G[K][i];
        }
        // Dijkstra
        int r = N-1;
        while (r--) {
            minn = INF;
            for (int i = 1; i <= N; ++i) {
                if (!s[i] && dis[i]<minn){
                    minn = dis[v=i];
                }
            }
            s[v] = 1;
            for (int i = 1; i <= N; ++i) {
                if (!s[i] && G[v][i]+minn<dis[i])
                    dis[i] = G[v][i]+minn;
            }
        }
        for (int i = 1; i <= N; ++i) {
            ans = dis[i]>ans?dis[i]:ans;
        }
        return ans==INF?-1:ans;
    }
};