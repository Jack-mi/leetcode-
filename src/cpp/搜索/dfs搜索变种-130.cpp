class Solution {
public:
    int m, n;
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis,int x, int y){
        for (int i = 0; i < 4; ++i) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if (nx<0||ny<0||nx>=m||ny>=n)
                continue;
            if (vis[nx][ny])
                continue;
            if (board[nx][ny] == 'X')
                continue;
            // 下一个是不在边界上的'O'
            vis[nx][ny] = 1;
            dfs(board, vis, nx, ny);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
            return ;
        m = board.size();
        n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // 关键思路：先从边界开始搜
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool isedge = i==0||j==0||i==m-1||j==n-1;
                if (isedge && board[i][j] == 'O') {
                    vis[i][j] = 1;
                    dfs(board, vis, i, j);
                }
            }
        }
        for (int i = 1; i < m-1; ++i) {
            for (int j = 1; j < n-1; ++j) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};