class Solution {
public:
    int pv, qv;
    TreeNode* ans;
    int flag = 0;
    /*
     * root为最近公共祖先的三个条件
     * （1）q和p分别位于左子树和右子树
     * （2）q为root且p位于左子树或右子树
     * （3）p为root且q位于左子树或右子树
     * */
    bool dfs(TreeNode* root) {
        if (!root)
            return false;
        if (flag)
            return true;
        bool l = dfs(root->left);
        if (flag)
            return true;
        bool r = dfs(root->right);
        if (flag)
            return true;
        if (l && r) {
            flag = 1;
            ans = root;
            return true;
        } else if (l) {
            if (root->val==pv ||root->val==qv) {
                flag = 1;
                ans = root;
            }
            return true;
        } else if (r) {
            if (root->val==pv ||root->val==qv) {
                flag = 1;
                ans = root;
            }
            return true;
        }
        return root->val == pv || root->val == qv;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pv = p->val;
        qv = q->val;
        dfs(root);
        return ans;
    }
};