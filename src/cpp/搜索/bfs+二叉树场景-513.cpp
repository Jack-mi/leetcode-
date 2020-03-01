class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            ans = cur->val;
            if (cur->right)
                q.push(cur->right);
            if (cur->left)
                q.push(cur->left);
        }
        return ans;
    }
};