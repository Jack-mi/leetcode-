#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
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
    Solution* s = new Solution();
    vector<int> nums = {4,3,2,7,8,2,3,1};
    string s1 = "pwwkew";
    string s2 = "abc";
    cout<<s->lengthOfLongestSubstring(s1)<<endl;
    return 0;
}
