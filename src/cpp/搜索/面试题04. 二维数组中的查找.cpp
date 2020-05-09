// way-1 binary search
class Solution {
public:
    int m, n, t;
    vector<vector<int>> Matrix;
    int flag = false;
    void bsearch(int left, int right, int top, int bottom) {
        // pop out conditoin
        if (left < 0 || right >= n || top < 0 || bottom >= m)
            return ;
        if (left > right || top > bottom)
            return ;
        // find the splitting point
        int mid = (left+right)/2;
        int row = 0;
        for (;row < m;row++) {
            int cur = Matrix[row][mid];
            if (cur == t) {
                flag = true;
                return ;
            } else if (cur > t) {
                break;
            }
        }
        // binary search
        bsearch(left, mid-1, row, bottom);
        if (flag)
            return ;
        bsearch(mid+1, right, top, row-1);
        if (flag)
            return ;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        Matrix = matrix;
        t = target;
        m = matrix.size();
        if (m <= 0)
            return false;
        n = matrix[0].size();
        if (n <= 0)
            return false;
        bsearch(0, n-1, 0, m-1);
        if (flag)
            return true;
        return false;
    }
};

// way-2 step by step
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m, n;
        m = matrix.size();
        if (m <= 0)
            return false;
        n = matrix[0].size();
        if (n <= 0)
            return false;
        int t = m+n;
        int row = 0;
        int col = n-1;
        // We'll walk at most m+n steps
        while (t--) {
            int cur = matrix[row][col];
            if (cur == target)
                return true;
                // down
            else if (cur < target) {
                row++;
                if (row >= m) {
                    return false;
                }
            }
                // left
            else {
                col--;
                if (col < 0) {
                    return false;
                }
            }
        }
        return false;
    }
};