/*
 * way-1：
 * 双指针遍历
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;
        unordered_set<char> hash;
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            if (hash.find(c) == hash.end()) {
                hash.insert(c);
            }
            else {
                while (l<r && hash.find(c)!=hash.end()) {
                    hash.erase(s[l]);
                    l++;
                }
                hash.insert(c);
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

/*
 * way2-双指针遍历优化
 * */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // l的初始位置为-1
        int l = -1;
        int ans = 0;
        vector<int> hash(128, -1);
        for (int r = 0; r < s.size(); ++r) {
            char c = s[r];
            // l指向滑动窗口左边界的左边一个位置
            l = max(l, hash[c]);
            hash[c] = r;
            ans = max(ans, r-l);
        }
        return ans;
    }
};