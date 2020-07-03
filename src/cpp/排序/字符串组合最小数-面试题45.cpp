class Solution {
public:
    struct cmp {
        bool operator()(const string& a, const string& b) {
            return a+b<b+a;
        }
    };
    string minNumber(vector<int>& nums) {
        vector<string> snums;
        /*
         * 考虑所有数都为0的情况
         * */
        int nonzero = 0;
        for (auto n:nums) {
            if (n != 0)
                nonzero = 1;
            char cur[10];
            sprintf(cur, "%d", n);
            string scur = string(cur);
            snums.push_back(scur);
        }
        if (nonzero == 0) {
            return "0";
        }
        sort(snums.begin(), snums.end(), cmp());
        string ans = "";
        for (auto s:snums)
            ans += s;
        return ans;
    }
};