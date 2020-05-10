class Solution {
public:
    vector<int> pre, in;
    /*
     * 4个参数分别为preorder和inorder的范围指针
     * 每次ps-pe指向的subtree和is-ie指向的subtree是相同的
     *
     * 递归函数的作用：
     * 返回preorder[ps:pe]和inorder[is:ie]共同指向的subtree
     *
     * 递归函数的两个返回点：
     * （1）当ps>pe，即二者指向的subtree为空时（特殊情况）
     * （2）当ps=pe，即二者指向的subtree只有一个节点时（子节点返回）
     * */
    TreeNode* build(int ps, int pe, int is, int ie) {
        if (ps > pe)
            return NULL;
        int rootval = pre[ps];
        TreeNode* root = new TreeNode(rootval);
        if (pe == ps)
            return root;
        int pos;
        for (int i = 0; i < in.size(); ++i) {
            if (in[i] == rootval) {
                pos = i;
                break;
            }
        }
        int left = pos-is;
        int right = ie-pos;
        root->left = build(ps+1, ps+left, is, pos-1);
        root->right = build(ps+left+1, pe, pos+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        return build(0, pre.size()-1, 0, in.size()-1);
    }
};