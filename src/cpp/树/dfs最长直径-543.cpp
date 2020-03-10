class Solution {
public:
    int ans = 0;
    int deepSearch(TreeNode* root) {
        if (!root)
            return 0;
        int ld = deepSearch(root->left);
        int rd = deepSearch(root->right);
        ans = max(ans, ld+rd);
        return max(ld, rd) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        deepSearch(root);
        return ans;
    }
};