#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
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

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
    }
};

int main()
{
    Solution* s=  new Solution();
    string ss = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    cout<<s->decodeString(ss)<<endl;
    return 0;
}
