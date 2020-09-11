class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, n, m;
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x,int y) {
        int ans = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            // border
            if (nx<0||ny<0||nx>=n||ny>=m)
                continue;
            // vis
            if (vis[nx][ny])
                continue;
            // 0
            if (!grid[nx][ny])
                continue;
            // normal
            vis[nx][ny] = 1;
            ans += dfs(grid, vis, nx, ny);
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 0)
            return 0;
        m = grid[0].size();
        if (m == 0)
            return 0;

        int ans = 1;
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    flag++;
                    continue;
                }
                vector<vector<int>> vis(n);
                for (int k = 0; k < n; ++k) {
                    vis[k].resize(m);
                }
                grid[i][j] = 1;
                vis[i][j] = 1;
                ans = max(ans, dfs(grid, vis, i, j));
                grid[i][j] = 0;
            }
        }
        if (flag == n*m)
            return n*m;
        return ans;
    }
};