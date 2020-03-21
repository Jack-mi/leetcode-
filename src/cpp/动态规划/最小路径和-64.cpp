class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        if (grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        // Initialization
        for (int i = 1; i < n; ++i)
            dp[0][i] = dp[0][i-1]+grid[0][i];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        // dp state transfer
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int cur = grid[i][j];
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cur;
            }
        }
        return dp[m-1][n-1];
    }
};