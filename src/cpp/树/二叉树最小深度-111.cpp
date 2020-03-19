class Solution {
public:
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        int flag = 0;
        while (!q.empty()) {
            ans ++;
            int len = q.size();
            while (len--) {
                TreeNode* cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {
                    flag = 1;
                    break;
                }
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (flag)
                break;
        }
        return ans;
    }
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        return bfs(root);
    }
};