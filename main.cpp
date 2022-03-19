#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <algorithm>
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
    ListNode(int x, ListNode* nxt = NULL) : val(x), next(nxt) {}
};

struct DlinkNode {
    int key, value;
    DlinkNode* prev, *next;
    DlinkNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkNode(int k, int v):key(k), value(v), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ans = nums[0];
        vector<vector<int>> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            dp[i].resize(2);
            dp[i][1] = nums[i];
        }
        dp[0][0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i][1] = max(dp[i-1][0]*nums[i], dp[i-1][1]*nums[i]);
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> arr1 = {3,9,20,15,7};
    vector<int> arr2 = {9,3,15,20,7};
    vector<vector<char>> g = {{'a'}, {'a'}};
    string str = "aaa";
    cout<<"hello world!"<<endl;
//    s->uniquePaths(3, 7);
    return 0;
}


