
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);    // 邻接表
        vector<int> degree(numCourses);         // 入度
        queue<int> zero;                        // 入度为0的队列
        int num = numCourses;                   // 还剩下多少入度不为0的队列
        for (auto p:prerequisites) {
            int in = p[0];
            int out = p[1];
            degree[in]++;
            adj[out].push_back(in);
        }
        for (int i = 0; i < numCourses;i++) {
            if (degree[i] == 0) {
                zero.push(i);
                num--;
            }
        }
        while (!zero.empty()) {
            int cur = zero.front();
            zero.pop();
            for (int i = 0; i < adj[cur].size(); ++i) {
                int nxt = adj[cur][i];
                if (--degree[nxt] == 0) {
                    zero.push(nxt);
                    num--;
                }
            }
        }
        if (num == 0)
            return true;
        return false;
    }
};