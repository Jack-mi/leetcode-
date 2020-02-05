class Solution {
public:
    vector<vector<int>> g;
    int mark[55][55];
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    int ans = 0;
    int dfs (int x, int y, int step) {
        int ac = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if (nx >= m || nx < 0 || ny >= n || ny < 0)
                continue;
            if (mark[nx][ny])
                continue;
            if (g[nx][ny] == 0)
                continue;
            mark[nx][ny] = 1;
            // 最重要的步骤：用dfs的方法统计连通图的面积没有mark[nx][ny] = 0;
            int l = dfs(nx , ny, step+1);
            ac += l;
        }
        return ac;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        g = grid;
        memset(mark, 0, sizeof(mark));
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0)
                    continue;
                mark[i][j] = 1;
                int l = dfs(i , j, 1);
                // key：此处要给所有的mark清0重新来
                memset(mark, 0, sizeof(mark));
                ans = l>ans?l:ans;
            }
        }
        return ans;
    }
};