class Solution {
public:
    vector<string> ans;
    void dfs(string cur, TreeNode* root) {
        if (!root) {
            return ;
        }
        cur += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(cur);
        } else {
            cur += "->";
            dfs(cur, root->left);
            dfs(cur, root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return ans;
        }
        dfs("", root);
        return ans;
    }
};