class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL&&t2==NULL) return true;
        if (t1==NULL&&t2!=NULL) return false;
        if (t2==NULL) return true;
        return isSub(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }
    bool isSub(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL&&t2==NULL) return true;
        if (t1==NULL&&t2!=NULL) return false;
        if (t2==NULL) return true;
        if (t1->val != t2->val)
            return false;
        return isSub(t1->left, t2->left)&&isSub(t1->right, t2->right);
    }
};