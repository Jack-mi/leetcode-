class Solution {
public:
    vector<vector<int>> ans;
    int s;
    void dfs(TreeNode* root, vector<int>& path, int acc) {
        if (!root->left && !root->right && acc==s) {
            ans.push_back(path);
            return ;
        }
        if (root->left) {
            int nxt = root->left->val;
            path.push_back(nxt);
            dfs(root->left, path, acc+nxt);
            path.pop_back();
        }
        if (root->right) {
            int nxt = root->right->val;
            path.push_back(nxt);
            dfs(root->right, path, acc+nxt);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return ans;
        vector<int> path;
        s = sum;
        path.push_back(root->val);
        dfs(root, path, root->val);
        return ans;
    }
};