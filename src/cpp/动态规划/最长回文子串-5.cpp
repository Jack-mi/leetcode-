class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005];
        int len = s.size();
        string ans = "";
        if (len == 0)
            return ans;
        // init
        for (int i = 0; i < len-1; ++i) {
            dp[i][i] = 1;
            dp[i][i+1] = s[i]==s[i+1]?1:0;
        }
        dp[len-1][len-1] = 1;
        // calculate dp
        for (int i = len-1; i >= 0; --i) {
            for (int j = i+2; j < len; ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (dp[i+1][j-1])
                        dp[i][j] = 1;
                }
            }
        }
        // print
//        for (int i = 0; i < len; ++i) {
//            for (int j = 0; j < len; ++j) {
//                cout<<dp[i][j]<<' ';
//            }
//            cout<<endl;
//        }


        int maxlen = -1;
        int ai(-1), aj(-1);
        // make ans
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (dp[i][j]) {
                    int gap = j-i+1;
                    if (gap > maxlen) {
                        maxlen = gap;
                        ai = i;
                        aj = j;
                    }
                }
            }
        }
        if (ai == -1) {
            return ans;
        } else {
            for (int i = ai; i <= aj; ++i) {
                ans += s[i];
            }
        }
        return ans;
    }
};