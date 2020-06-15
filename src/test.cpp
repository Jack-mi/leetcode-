#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = 0;

void dfs(TreeNode* root, int acc) {
    if (!root->left && !root->right) {
        ans = max(ans, acc);
        return ;
    }
    if (root->left) {
        int nxt_val = acc+root->left->val;
        dfs(root->left, nxt_val);
    }
    if (root->right) {
        int nxt_val = acc+root->right->val;
        dfs(root->right, nxt_val);
    }
}

int main()
{
    TreeNode* root = new TreeNode(0);
    dfs(root, root->val);
    // return ans;
    return 0;
}