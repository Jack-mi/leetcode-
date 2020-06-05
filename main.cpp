#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <cmath>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int ans = nums[0];
        if (len == 1)
            return ans;
        vector<int> dp(len);
        dp[0] = ans;
        for (int i = 1; i < len; ++i) {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    string ss = "abc";
    Solution* s = new Solution();
    s->maxSubArray(num);
    return 0;
}
