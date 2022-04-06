class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return root;
        }
        if (!root->left && !root->right) {
            Node* cur = root;
            root->left = cur;
            root->right = cur;
            return root;
        }
        Node* head;
        Node* afterL = treeToDoublyList(root->left);
        Node* afterR = treeToDoublyList(root->right);
        if (!afterL && afterR) {
            root->right = afterR;
            afterR->left = root;
            int initR = afterR->val;
            while(afterR->right->val != initR) {
                afterR = afterR->right;
            }
            afterR->right = root;
            root->left = afterR;
            head = root;
        } else if (afterL && !afterR) {
            head = afterL;
            root->right = head;
            afterL->left = root;
            int initL = afterL->val;
            while(afterL->right->val != initL) {
                afterL = afterL->right;
            }
            afterL->right = root;
            root->left = afterL;
        }
        if (afterL && afterR) {
            head = afterL;
            root->right = afterR;
            afterR->left = root;
            int initR = afterR->val;
            while(afterR->right->val != initR) {
                afterR = afterR->right;
            }
            afterR->right = afterL;
            afterL->left = afterR;
            int initL = afterL->val;
            while(afterL->right->val != initL) {
                afterL = afterL->right;
            }
            afterL->right = root;
            root->left = afterL;
        }
        return head;
    }
};
