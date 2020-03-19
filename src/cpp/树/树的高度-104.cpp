class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        return max(l, r);
    }
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        return dfs(root);
    }
};