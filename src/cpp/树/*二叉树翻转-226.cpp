
// 递归法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        TreeNode* r = invertTree(root->left);
        TreeNode* l = invertTree(root->right);
        root->right = r;
        root->left = l;
        return root;
    }
};
