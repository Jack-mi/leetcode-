class Solution {
public:
    int translateNum(int num) {
        char cnum[20];
        sprintf(cnum, "%d", num);
        string snum = string(cnum);
        int len = snum.size();
        // num size = 1
        if (len == 1)
            return 1;
        vector<int> dp(len, 1);
        if (snum[len-2]=='1' || snum[len-2]=='2'&&snum[len-1]<'6')
            dp[len-2] = 2;
        // num size = 2
        if (len == 2)
            return dp[0];
        // num size >= 3
        for (int i = len-3; i >= 0; --i) {
            char cur = snum[i];
            if (cur=='1') {
                dp[i] = dp[i+1]+dp[i+2];
            } else if(cur == '2') {
                if (snum[i+1] < '6')
                    dp[i] = dp[i+1]+dp[i+2];
                else
                    dp[i] = dp[i+1];
            } else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};