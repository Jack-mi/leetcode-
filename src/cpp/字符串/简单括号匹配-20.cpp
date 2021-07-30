class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len % 2 != 0)
            return false;

        unordered_map<char, char> kh = {
                {')', '('},
                {']', '['},
                {'}', '{'}
        };
        stack<char> sa;
        for (auto c: s) {
            if(c=='(' || c=='[' || c=='{') {
                sa.push(c);
            } else {
                if (sa.empty())
                    return false;
                char tmp = sa.top();
                sa.pop();
                if (tmp != kh[c])
                    return false;
            }
        }
        if (!sa.empty())
            return false;
        return true;
    }
};