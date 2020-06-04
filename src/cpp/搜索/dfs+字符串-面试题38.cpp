/*
 * 排列组合的思路：
 * 递归的层数代表排列的最终位置
 * 每层递归的for循环代表每个位置可能的值
 * */
class Solution {
public:
    vector<string> ans;
    set<string> sans;
    string st;
    vector<char> cur;
    int len;
    int vis[10];
    string vec2str() {
        string ans = "";
        for (int i = 0; i < cur.size(); ++i) {
            ans.push_back(cur[i]);
        }
        return ans;
    }
    void dfs(int step) {
        for (int i = 0; i < len; ++i) {
            if (!vis[i]) {
                if (step == len-1) {
                    cur.push_back(st[i]);
                    string cc = vec2str();
                    sans.insert(cc);
                    cur.pop_back();
                    return ;
                } else {
                    vis[i] = 1;
                    cur.push_back(st[i]);
                    dfs(step+1);
                    vis[i] = 0;
                    cur.pop_back();
                }
            }
        }
    }
    vector<string> permutation(string s) {
        st = s;
        len = s.size();
        if (len == 1) {
            ans.push_back(s);
            return ans;
        }
        for (int i = 0; i < len; ++i) {
            vis[i] = 1;
            cur.push_back(s[i]);
            dfs(1);
            cur.pop_back();
            vis[i] = 0;
        }
        // 用set来去重
        for (auto s: sans) {
            ans.push_back(s);
        }
        return ans;
    }
};