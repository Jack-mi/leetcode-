class Solution {
public:
    struct cmp {
        bool operator() (const pair<char, int> & a, const pair<char, int> & b) {
            return a.second > b.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c:s)
            mp[c] += 1;
        vector<pair<char, int>> vec;
        for (auto c:mp) {
            vec.emplace_back(c.first, c.second);
        }
        sort(vec.begin(), vec.end(), cmp());
        string ans = "";
        for (auto vc: vec) {
            int tmp = vc.second;
            while (tmp--)
                ans += vc.first;
        }
        return ans;
    }
};