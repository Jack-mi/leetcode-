class Solution {
public:
    typedef struct {
        int paiming[27];
        int flag;
        char zi;
    }ss ;

    struct cmp {
        bool operator() (const ss& a, const ss& b) {
            for (int i = 1; i < 27; ++i) {
                if (a.paiming[i]>b.paiming[i])
                    return true;
                if (a.paiming[i]<b.paiming[i])
                    return false;
            }
            return a.zi<b.zi;
        }
    };
    int char2int(char x) {
        return x-'A'+1;
    }
    string rankTeams(vector<string>& votes) {
        vector<ss> ans(27);
        for (auto v:votes) {
            int cnt = 1;
            for (auto c:v) {
                int x = char2int(c);
                ans[x].flag = 1;
                ans[x].paiming[cnt] ++;
                ans[x].zi = c;
                cnt++;
            }
        }
        sort(ans.begin(), ans.end(), cmp());
        string res = "";
        for (int i = 0; i < 27; ++i) {
            if (ans[i].flag) {
                res += ans[i].zi;
            }
        }
        return res;
    }
};