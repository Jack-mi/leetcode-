class Solution {
public:
    vector<TreeNode*> start;
    void isSubTree(TreeNode* A, TreeNode* B) {
        if (!A)
            return ;
        if (A->val == B->val)
            start.push_back(A);
        isSubTree(A->left, B);
        isSubTree(A->right, B);
    }
    bool isContain(TreeNode* a, TreeNode* b) {
        if (!a && b)
            return false;
        if (!a && !b || a && !b)
            return true;
        return (a->val==b->val) && isContain(a->left, b->left) && isContain(a->right, b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return false;
        isSubTree(A, B);
        if (start.size() == 0)
            return false;
        for (auto s:start) {
            if (isContain(s, B))
                return true;
        }
        return false;
    }
};