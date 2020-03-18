class Solution {
public:
    TreeNode* buildTree2(vector<int>& pre, int& pos, vector<int>& ino, int start, int end) {
        if (pos >= pre.size())
            return NULL;
        int i = start;
        for (; i <= end; ++i) {
            if (ino[i] == pre[pos])
                break;
        }
        TreeNode* root = new TreeNode(pre[pos]);
        // 此处pos的值是全局变量，关键在于preorder数组是递归的，所以pos要累加
        if (i-1 >= start)
            root->left = buildTree2(pre, ++pos, ino, start, i-1);
        if (i+1 <= end)
            root->right = buildTree2(pre, ++pos , ino , i+1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return buildTree2(preorder, pos, inorder, 0, inorder.size()-1);
    }
};