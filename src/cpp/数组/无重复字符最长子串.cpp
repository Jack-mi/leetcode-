class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int p1(0), p2(0), ans(0);
        while (p2 < s.length()) {
            char cr = s[p2];
            window[cr]++;
            p2++;
            while (window[cr] > 1) {
                char cl = s[p1];
                window[cl]--;
                p1++;
            }
            ans = p2-p1>ans?p2-p1:ans;
        }
        return ans;
    }
};