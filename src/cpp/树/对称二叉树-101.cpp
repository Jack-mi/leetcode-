class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while (!q.empty()) {
            int len = q.size();
            if (len%2!=0 && !cnt) {
                return false;
            }
            cnt = 0;
            vector<int> vec(len);
            for (int i = 0; i < len; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
                vec[len] = cur?cur->val:INT_MAX;
            }
            for (int i = 0; i < len/2; ++i) {
                if (vec[i] != vec[len-i-1])
                    return false;
            }
        }
        return true;
    }
};