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

};

int main() {
    vector<int> num = {3,30,34,5,9};
    vector<vector<int>> nn = {{1,2,5},{3,2,1}};
    string str = "abcabcbb";
    Solution* s = new Solution();
    s->lengthOfLongestSubstring(str);
    return 0;
}
