class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int mlen = INT_MAX;
        int p1(0), p2(0), match(0);
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for (char c: t) needs[c]++;
        // 滑动窗口关键的一步：在每次判断当前子串是否满足needs要求时，不能用for循环
        while (p2 < s.size()) {
            char cr = s[p2];
            window[cr]++;
            if (needs.count(cr) && window[cr] == needs[cr])
                match++;
            p2++;
            while (match == needs.size()) {
                if (p2-p1 < mlen) {
                    mlen = p2-p1;
                    ans = s.substr(p1, p2-p1);
                }
                char cl = s[p1];
                window[cl]--;
                if (needs.count(cl) && window[cl] < needs[cl])
                    match--;
                p1++;
            }
        }
        return ans;
    }
};