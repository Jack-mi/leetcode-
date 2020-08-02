class Solution {
public:
    typedef struct {
        int height;
        int idx;
    } p;
    vector<p> allp, ans;
    struct cmp {
        bool operator() (const p& a, const p& b) {
            if (a.height == b.height)
                return a.idx < b.idx;
            return a.height > b.height;
        }
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> rans;
        if (people.size() == 0)
            return rans;
        for (int i = 0; i < people.size(); ++i) {
            p tmp;
            tmp.height = people[i][0];
            tmp.idx = people[i][1];
            allp.push_back(tmp);
        }
        sort(allp.begin(), allp.end(), cmp());
        p last = allp[0];
        ans.push_back(last);
        for (int i = 1; i < allp.size(); ++i) {
            p cur = allp[i];
            int target = cur.idx;
            ans.insert(ans.begin()+target, cur);
            last = cur;
        }
        for (auto c:ans) {
            vector<int> tmp;
            tmp.push_back(c.height);
            tmp.push_back(c.idx);
            rans.push_back(tmp);
        }
        return rans;
    }
};