class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root==NULL && head!=NULL) return false;
        return isSub(head, root)||isSubPath(head, root->left)||isSubPath(head, root->right);
    }
    // 关键在于这个函数，每次只确认以root为头的和以head为头的
    bool isSub(ListNode* head, TreeNode* root) {
        if (head == NULL) return true;
        if (root==NULL && head!=NULL) return false;
        if (head->val != root->val)
            return false;
        return isSub(head->next, root->left)||isSub(head->next, root->right);
    }
};