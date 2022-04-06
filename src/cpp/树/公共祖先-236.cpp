class Solution {
public:
    TreeNode* a, *b, *ans;
    bool bothChild(TreeNode* root) {
        if (!root) {
            return false;
        }
        bool lr = bothChild(root->left);
        bool rr = bothChild(root->right);
        if (lr&&rr || ((root->val == a->val || root->val == b->val)&&(lr||rr))) {
            ans = root;
        }
        return root->val == a->val || root->val == b->val || lr || rr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = p;
        b = q;
        bothChild(root);
        return ans;
    }
};