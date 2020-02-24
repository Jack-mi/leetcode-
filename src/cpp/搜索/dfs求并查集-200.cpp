class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int m, n;
    void dfs(vector<vector<char>>& grid, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if (nx<0||ny<0||nx>=m||ny>=n)
                continue;
            if (grid[nx][ny] == '1') {
                grid[nx][ny] = '0';
                dfs(grid, nx, ny);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size()==0)
            return 0;
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, i, j);
                    ans ++;
                }
            }
        }
        return ans;
    }
};