class Solution {
public:
    bool find(string s, vector<string>& wordDict) {
        for (auto w:wordDict) {
            if (w == s)
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<int> dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] == false)
                    continue;
                string cur = s.substr(j, i-j);
                if(find(cur, wordDict)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};