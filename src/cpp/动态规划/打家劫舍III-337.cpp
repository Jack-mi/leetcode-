class Solution {
public:
    typedef struct {
        int yes;
        int no;
    } res;
    res dfs(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        res ans;
        res l = dfs(root->left);
        res r = dfs(root->right);
        ans.yes = root->val + l.no + r.no;
        ans.no = max(max(l.yes+r.yes, l.no+r.no), max(l.yes+r.no, l.no+r.yes));
        return ans;
    }
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        res ans = dfs(root);
        return max(ans.no, ans.yes);
    }
};
