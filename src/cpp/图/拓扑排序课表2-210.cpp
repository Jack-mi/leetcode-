
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int num = numCourses;
        vector<vector<int>> adj(num);
        vector<int> degree(num);
        queue<int> zero;
        for (auto p:prerequisites) {
            int in = p[0];
            int out = p[1];
            degree[in]++;
            adj[out].push_back(in);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) {
                zero.push(i);
                num--;
            }
        }
        vector<int> ans;
        while (!zero.empty()) {
            int cur = zero.front();
            zero.pop();
            ans.push_back(cur);
            for (int i = 0; i < adj[cur].size(); ++i) {
                int nxt = adj[cur][i];
                if (--degree[nxt] == 0) {
                    zero.push(nxt);
                    num--;
                }
            }
        }
        if (ans.size() == numCourses)
            return ans;
        return vector<int> {};
    }
};