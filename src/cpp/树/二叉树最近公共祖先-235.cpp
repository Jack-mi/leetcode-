
// 迭代
class Solution {
public:
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv = p->val;
        int qv = q->val;
        while (root != NULL) {
            int cen = root->val;
            if (pv>cen&&qv>cen) {
                root = root->right;
            } else if (pv<cen&&qv<cen) {
                root = root->left;
            } else {
                return root;
            }
        }
        return NULL;
    }
};

// 递归
class Solution {
public:
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int cen = root->val;
        int pv = p->val;
        int qv = q->val;
        TreeNode* ans = NULL;
        if (pv<cen&&qv<cen)
            return lowestCommonAncestor(root->left, p, q);
        else if (pv>cen&&qv>cen)
            return lowestCommonAncestor(root->right, p, q);
        else
            ans = root;
        return ans;
    }
};