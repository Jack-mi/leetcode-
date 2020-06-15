class Solution {
public:
    struct cmp {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[0]==b[0]?a[1]<a[1]:a[0]<b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0)
            return ans;
        sort(intervals.begin(), intervals.end(), cmp());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> last = ans.back();
            ans.pop_back();
            vector<int> cur = intervals[i];
            if (last[1]>=cur[0] && last[1]<cur[1]) {
                last[1] = cur[1];
                ans.push_back(last);
            }
            else if (last[1]>=cur[1]) {
                ans.push_back(last);
            }
            if (last[1] < cur[0]){
                ans.push_back(last);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};