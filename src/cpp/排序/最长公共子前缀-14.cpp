// 排序后比较第一个和最后一个
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0)
            return ans;
        sort(strs.begin(), strs.end());
        int i = 0, j = 0;
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++;
                j++;
            } else {
                break;
            }
        }
        return ans;
    }
};