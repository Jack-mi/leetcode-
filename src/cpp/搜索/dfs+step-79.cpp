class Solution {
public:
    vector<vector<char>> cboard;
    int m, n;
    string cword;
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<bool>> mark;
    bool dfs(int x, int y, int step) {
        if (cboard[x][y] != cword[step])
            return false;
        else {
            if (step == cword.size()-1)
                return true;
            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                // 搜索的关键(1)边界问题
                if (nx >= m || ny >= n || nx < 0 || ny < 0)
                    continue;
                // 搜索的关键(2)标记问题
                if (mark[nx][ny])
                    continue;
                mark[x][y] = true;
                int f = dfs(nx, ny, step+1);
                mark[x][y] = false;
                if (f)
                    return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        cboard = board;
        cword = word;
        if (word.size() == 0)
            return true;
        if (board.size() == 0)
            return false;
        m = board.size();
        n = board[0].size();
        // 初始化二维vector
        mark.resize(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mark[i].push_back(false);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};