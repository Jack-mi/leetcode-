class Solution {
public:
    void show(vector<vector<int>> dp) {
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp.size(); ++j) {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            dp[i].resize(s.size());
            dp[i][i] = 1;
        }
//        show(dp);
        for (int gap = 1; gap < s.size(); ++gap) {
            for (int row = 0; row < s.size(); ++row) {
                int col = row+gap;
                if (col >= s.size())
                    break;
                if (s[row] == s[col])
                    dp[row][col] = dp[row+1][col-1] + 2;
                else
                    dp[row][col] = max(dp[row+1][col], dp[row][col-1]);
            }
        }
//        show(dp);
        return dp[0][s.size()-1];
    }
};