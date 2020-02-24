class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> list;
            while (size--) {
                TreeNode* cur = q.front();
                q.pop();
                list.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (list.size() != 0)
                ans.push_back(list);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};