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
    string longestPalindrome(string s) {
        if (s == "")
            return "";
        vector<vector<int>> dp(s.size());
        for (int i = 0; i < s.size(); ++i) {
            dp[i].resize(s.size());
            dp[i][i] = 1;
        }
        for (int i = 0; i < s.size()-1; ++i) {
            dp[i][i+1] = s[i]==s[i+1]?1:0;
        }
        for (int shift = 2; shift < s.size(); ++shift) {
            for (int row = 0; row < s.size(); ++row) {
                int col = row+shift;
                if (col >= s.size())
                    break;
                if (s[row] != s[col])
                    dp[row][col] = 0;
                else
                    dp[row][col] = dp[row+1][col-1];
            }
        }

//        show(dp);
        int ans_l = 0;
        string ans_s = "";
        for (int i = 0; i < s.size(); ++i) {
            int gap = 0;
            for (int j = i; j < s.size(); ++j) {
                if (dp[i][j]) {
                    gap = j-i+1;
                    if (gap > ans_l) {
                        ans_l = gap;
                        ans_s = s.substr(i, gap);
                    }
                }
            }
        }
        return ans_s;
    }
};