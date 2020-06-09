class Solution {
public:
    int m, n;
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 1;
        // matrix is empty
        m = matrix.size();
        if (m == 0)
            return 0;
        n = matrix[0].size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp;
        dp.resize(m);
        for (int i = 0; i < m; ++i) {
            dp[i].resize(n);
        }
        int flag = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    flag = 1;
                }
            }
        }
        // all matrix is composed of '0'
        if (!flag)
            return 0;

        // dynamic programming
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j]=='0')
                    continue;
                if (matrix[i-1][j-1]=='1' && matrix[i-1][j]=='1' && matrix[i][j-1]=='1') {
                    /*
                     * dp[i][j]表示以(i,j)为右下角的正方形最大长度
                     * 只有当left，up和左上方的点都为'1'，且当前点也为'1'时才进行状态转移
                     * 转移的逻辑为left，up和左上角点最小值+1
                     * */
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
//                    int total = dp[i-1][j-1];
//                    int up = dp[i-1][j];
//                    int left = dp[i][j-1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        // test
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout<<dp[i][j]<<' ';
//            }
//            cout<<endl;
//        }
        return ans*ans;
    }
};