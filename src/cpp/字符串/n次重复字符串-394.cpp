class Solution {
public:
    string S;
    int I ;
    int getnum(int idx) {
        string snum = "";
        for (int i = idx; i < S.size(); ++i) {
            snum.push_back(S[i]);
            if (S[i+1] == '[')
                break;
        }
        int num = 0;
        int f = 1;
        for (int i = snum.size()-1; i >= 0; i--) {
            num += f*(snum[i]-'0');
            f *= 10;
        }
        return num;
    }
    string getString(int idx) {
        string ans = "";
        string in = "";
        int num = getnum(idx);
        while (S[idx] != '[')
            idx++;
        for (I = idx+1; I < S.size(); ++I) {
            if (S[I]>='0'&&S[I]<='9')
                in += getString(I);
            else if (S[I] == ']')
                break;
            else
                in += S[I];
        }
        while (num--)
            ans += in;
        return ans;
    }
    string decodeString(string s) {
        S = s;
        int num = -1;
        string ans = "";
        for (I = 0; I < s.size(); ++I) {
            if (s[I]>='0'&&s[I]<='9')
                ans += getString(I);
            else
                ans += s[I];
        }
        return ans;
    }
};