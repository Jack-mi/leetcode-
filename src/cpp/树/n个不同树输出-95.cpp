class Solution {
public:
    vector<TreeNode*> buildTree(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end)
            ans.push_back(NULL);
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = buildTree(start, i-1);
            vector<TreeNode*> right = buildTree(i+1, end);
            for (auto x:left) {
                for (auto y:right) {
                    // 每次向vector内push一个ptr节点，都要重新创建
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0)
            return res;
        res = buildTree(1, n);
        return res;
    }
};