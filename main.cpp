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
    string ans = "";
    string decodeString(string s) {
        if (s.size() == 0)
            return ans;
        for (int i = 0; i < s.size(); ++i) {

        }
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
