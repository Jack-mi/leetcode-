class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // initialize dp
        vector<vector<int>> dp;
        dp.resize(m);
        for (int i = 0; i < m; ++i) {
            dp[i].resize(n);
        }
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }
        // calculate
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};