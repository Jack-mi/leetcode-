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
    int tar, len;
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> candi;
    void dfs(int start, int acc) {
        if (acc == tar) {
            ans.push_back(path);
            return ;
        }
        for (int i = start; i < len; ++i) {
            if (candi[i] > tar)
                break;
            if (acc + candi[i] > tar)
                return ;
            path.push_back(candi[i]);
            dfs(i, acc+candi[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candi = candidates;
        len = candidates.size();
        tar = target;
        for (int i = 0; i < len; ++i) {
            if (candidates[i] > target)
                break;
            path.push_back(candidates[i]);
            dfs(i, candidates[i]);
            path.pop_back();
        }
        return ans;
    }
};

int main() {
    vector<int> num = {1,2,3};
    vector<vector<int>> nn = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    string str = "abcabcbb";
    Solution* s = new Solution();
    int n = 0;
    int m = 3;
    s->permute(num);
    return 0;
}
