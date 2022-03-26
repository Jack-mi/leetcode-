// way 1
class Solution {
public:
    unordered_map<char, int> t_set, s_set;
    bool check() {
        for (auto x: t_set) {
            if (s_set[x.first] < x.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        if (s.size() == t.size() && s.size() == 1) {
            if (s[0] == t[0]) return s;
            return "";
        }
        for (auto x: t) {
            if (t_set.count(x) > 0) {
                t_set[x]++;
            } else {
                t_set.emplace(x, 1);
            }
        }
        int start(0), end(0), flag(0);
        for (int i = 0; i < s.size(); ++i) {
            char cur = s[i];
            if (t_set.count(cur) > 0 && !flag) {
                flag = 1;
                start = i;
                break;
            }
        }
        flag = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            char cur = s[i];
            if (t_set.count(cur) > 0 && !flag) {
                flag = 1;
                end = i;
                break;
            }
        }
        if (end - start + 1 < t.size()) {
            return "";
        }
        int l(start), r(start);
        s_set[s[r]]++;
        if (check()) {
            return t;
        }
        int ans = s.size();
        string sans = "";
        while (l <= r && r < end) {
            s_set[s[++r]]++;
            while (check() && l<=r) {
                if (r-l+1 <= ans) {
                    ans = r-l+1;
                    sans = s.substr(l, ans);
                }
                if (t_set.count(s[l]) != 0) {
                    s_set[s[l]]--;
                }
                l++;
            }
        }
        return sans;
    }
};


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