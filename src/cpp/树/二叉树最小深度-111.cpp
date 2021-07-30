// way-1
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

// way-2
class Solution {
public:
    int ans = INT_MAX;

    void dfs(TreeNode* root, int depth) {
        if (!root->left && !root->right) {
            ans = min(ans, depth);
            return ;
        }
        if (root->left)
            dfs(root->left, depth+1);
        if (root->right)
            dfs(root->right, depth+1);
    }

    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        dfs(root, 1);
        return ans;
    }
};