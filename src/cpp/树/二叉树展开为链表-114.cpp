class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return ;
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* end = root;
        while (end->right) {
            end = end->right;
        }
        end->right = tmp;
        flatten(root->right);
    }
};