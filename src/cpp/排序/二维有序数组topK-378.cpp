// 二分查找法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();
        while (left < right) {
            int mid = (right+left)/2;
            // 计算mid在矩阵中算是第几大的元素
            int cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            // 关键：最终的第k大元素肯定不在[left, right]中，要+1
            if (cnt < k)
                left = mid+1;
                // 关键：最终的第k大元素肯定在[left, mid]中
            else
                right = mid;
        }
        return left;
    }
};

// 堆排序
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                q.push(matrix[i][j]);
            }
        }
        int n = matrix.size()*matrix[0].size();
        int ans;
        while (k--) {
            ans = q.top();
            q.pop();
        }
        return ans;
    }
};