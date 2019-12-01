//
// Created by 刘小粟 on 2019/12/1.
//

#ifndef LEETCODE_Q3_H
#define LEETCODE_Q3_H


class Q3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charset;
        int start(0), end(0), ans(0), length(0);
        while (end < s.length()) {
            char tmpchar = s[end];
            if(charset.find(tmpchar) != charset.end()) {
                start = charset[tmpchar]+1>start?charset[tmpchar]+1:start;
            }
            ans = (end-start+1)>ans?(end-start+1):ans;
            charset[tmpchar] = end++;
        }
        return ans;
    }
};


#endif //LEETCODE_Q3_H
