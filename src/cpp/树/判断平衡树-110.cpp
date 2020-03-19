class Solution {
public:
    int flag = 1;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        if (!flag)
            return 0;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        if (l-r>1 || r-l>1) {
            flag = 0;
            return 0;
        }
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};