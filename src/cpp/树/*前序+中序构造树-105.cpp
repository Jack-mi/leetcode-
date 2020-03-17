#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution {
    public:
        TreeNode* buildTree2(vector<int>& pre, int pos, vector<int>& ino, int start, int end) {
            if (pos >= pre.size())
                return NULL;
            int i = start;
            for (; i <= end; ++i) {
                if (ino[i] == pre[pos])
                    break;
            }
            TreeNode* root = new TreeNode(pre[pos]);
            if (i-1 >= start)
                root->left = buildTree2(pre, pos+1, ino, start, i-1);
            if (i+1 <= end)
                root->right = buildTree2(pre, pos+2 , ino , i+1, end);
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int pos = 0;
            return buildTree2(preorder, pos, inorder, 0, inorder.size()-1);
        }
    };
    return 0;
}
