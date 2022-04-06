// way1
class Solution {
public:
    bool sym(TreeNode* q, TreeNode* p) {
        if (q&&!p || !q&&p) {
            return false;
        }
        else if (!q && !p) {
            return true;
        }
        else {
            if (q->val != p->val) {
                return false;
            }
            return sym(q->left, p->right) && sym(q->right, p->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return false;
        return sym(root->left, root->right);
    }
};

// way2
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