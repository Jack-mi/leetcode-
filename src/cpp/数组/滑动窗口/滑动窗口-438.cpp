class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for(char c : p) needs[c]++;
        int p1(0), p2(0), match(0);
        vector<int> ans;
        while (p2 < s.size()) {
            char cr = s[p2];
            window[cr]++;
            if (needs.count(cr) && window[cr] == needs[cr])
                match ++;
            p2++;
            while (match == needs.size()) {
                if (p2-p1 == p.size())
                    ans.push_back(p1);
                char cl = s[p1];
                window[cl]--;
                if (needs.count(cl)  && window[cl] < needs[cl])
                    match--;
                p1++;
            }
        }
        return ans;
    }
};