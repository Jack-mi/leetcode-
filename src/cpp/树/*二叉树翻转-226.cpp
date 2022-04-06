class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode* ans = new TreeNode(root->val);
        ans->left = invertTree(root->right);
        ans->right = invertTree(root->left);
        return ans;
    }
};