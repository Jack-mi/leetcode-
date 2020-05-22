class Solution {
public:
    vector<int> post;
    int len;
    bool fun(int left, int right, int root) {
        if (left == right && right == root)
            return true;
        if (left > right || right > root)
            return false;
        // if there's any num smaller than root in (right, root)
        for (int i = right; i < root; ++i) {
            if (post[i] < post[root]) {
                return false;
            }
        }
        // find left's right
        int left_r = right-1;
        for (int i = left; i < right-1; ++i) {
            if (post[i] > post[right-1]) {
                left_r = i;
                break;
            }
        }
        // find right's right
        int right_r = root-1;
        for (int i = right; i < root-1; ++i) {
            if (post[i] > post[root-1]) {
                right_r = i;
                break;
            }
        }
        /*
         * 本题关键：如果在递归的时候只需要递归到left child和right child
         * 就只递归这一个，不用都递归，不然会出现l>r的错误
         * */
        if (root == right) {
            return fun(left, left_r, right-1);
        }
        else if (left == right) {
            return fun(right, right_r, root-1);
        }
        else
            return fun(left, left_r, right-1) && fun(right, right_r, root-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        post = postorder;
        len = post.size();
        if (len==0 || len==1)
            return true;
        int r = len-1;
        int l = 0;
        for (int i = 0; i < len-1; ++i) {
            if (post[i] > post[len-1]) {
                r = i;
                break;
            }
        }
        return fun(l, r, len-1);
    }
};