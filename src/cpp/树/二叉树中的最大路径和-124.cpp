class Solution {
public:
    int ans = INT_MIN;
    int maxGain(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int cur = root->val;
        int lnum = max(maxGain(root->left), 0);
        int rnum = max(maxGain(root->right), 0);
        ans = max(ans, cur+lnum+rnum);
        return root->val + max(lnum, rnum);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return ans;
    }
};
