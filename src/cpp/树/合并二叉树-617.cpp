class Solution {
public:
    TreeNode* dfs(TreeNode* t1, TreeNode* t2) {
        if (!t1&&!t2)
            return NULL;
        else if (t1 && !t2) {
            return t1;
        } else if (!t1 && t2) {
            return t2;
        } else {
            t1->val += t2->val;
            t1->left = dfs(t1->left, t2->left);
            t1->right = dfs(t1->right,t2->right);
        }
        return t1;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return dfs(t1, t2);
    }
};