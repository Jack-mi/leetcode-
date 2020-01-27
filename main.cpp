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
        bool judge(string s, string t, int p1, int p2, unordered_map<char, int>& hasht) {
            unordered_map<char, int> hashc;
            string sub = s.substr(p1, p2-p1+1);
            setHash(sub, hashc);
            bool flag = true;
            for (unordered_map<char, int>::iterator mit = hasht.begin(); mit != hasht.end(); mit++) {
                char curk = mit->first;
                int curv = mit->second;
                unordered_map<char, int>::iterator mit2 = hashc.find(curk);
                if (mit2 == hashc.end()) {
                    flag = false;
                    break;
                }
                int cnt = mit2->second;
                if (cnt < curv) {
                    flag = false;
                    break;
                }
            }
            return flag;
        }
        void setHash(string& s, unordered_map<char, int>& hash) {
            for (int i = 0; i < s.length(); ++i) {
                if (hash.find(s[i]) == hash.end()) {
                    hash[s[i]] = 1;
                } else {
                    hash[s[i]]++;
                }
            }
        }
        string minWindow(string s, string t) {
            string ans = "";
            int mlen = INT_MAX;
            int p1(0), p2(0);
            unordered_map<char, int> hasht;
            setHash(t, hasht);
            while (p1 < s.length() && p2 < s.length()) {
                if (judge(s, t, p1, p2, hasht)) {
                    if (p2-p1+1 < mlen) {
                        mlen = p2-p1+1;
                        ans = s.substr(p1, p2-p1+1);
                    }
                    p1++;
                } else {
                    p2++;
                }
            }
            return ans;
        }
    };
    Solution* s = new Solution();
    vector<int> nums = {4,3,2,7,8,2,3,1};
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";
    cout<<s->minWindow(s1, s2)<<endl;
    return 0;
}
