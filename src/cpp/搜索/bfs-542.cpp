class Solution {
public:
    int m, n;
    using value_t = pair<int, int>;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int bfs(vector<vector<int>>& matrix, int x, int y) {
        int ans = 0;
        queue<value_t> q;
        q.push(value_t(x, y));
        int flag = 0;
        while (!q.empty()) {
            int t = q.size();
            ans++;
            while (t--) {
                value_t cur = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = cur.first+dir[i][0];
                    int ny = cur.second+dir[i][1];
                    if (nx<0||ny<0||nx>=m||ny>=n)
                        continue;
                    if (matrix[nx][ny] == 0) {
                        flag = 1;
                        break;
                    }
                    else
                        q.push(value_t(nx, ny));
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        return ans;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> ans;
        ans.resize(m);
        for (int i = 0; i < m; ++i) {
            ans[i].resize(n);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[i][j] = matrix[i][j]==0?0:bfs(matrix, i, j);
            }
        }
        return ans;
    }
};