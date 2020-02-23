class Solution {
public:
    int numSquares(int n) {
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(n);
        return bfs(q, vis, 0, n);
    }
    int bfs(queue<int>& q, vector<bool>& vis, int step, int& n) {
        while (!q.empty()) {
            int size = q.size();
            step++;
            while (size--) {
                int cur = q.front();
                q.pop();
                int i = sqrt(cur);
                for (; i >= 1; --i) {
                    int left = cur-i*i;
                    if (left == 0) {
                        return step;
                    }
                    if (!vis[left]) {
                        q.push(left);
                        vis[left] = true;
                    }
                }
            }
        }
        return -1;
    }
};