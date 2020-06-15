class Solution {
public:
    string num2str(int n) {
        char str[100];
        sprintf(str, "%d", n);
        return string(str);
    }
    struct cmp {
        bool operator() (const string& a, const string& b) {
            return a+b>b+a;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        if (nums.size() == 0)
            return "";
        int Max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            snums.push_back(num2str(nums[i]));
            Max = max(Max, nums[i]);
        }
        /*
         * 坑：如果所有元素都为0
         * */
        if (Max == 0) {
            return "0";
        }
        sort(snums.begin(), snums.end(), cmp());
        string ans = "";
        for (int i = 0; i < snums.size(); ++i) {
            ans += snums[i];
        }
        return ans;
    }
};