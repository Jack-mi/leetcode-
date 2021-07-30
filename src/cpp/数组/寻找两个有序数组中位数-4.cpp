// way1:O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m+n;
        int last, cur;
        int i1(0), i2(0);
        // 关键在于如何从每轮遍历中筛选出小的那个值
        for (int i = 0; i <= len/2; ++i) {
            last = cur;
            if (i1<m && (i2>=n || nums1[i1]<nums2[i2]))
                cur = nums1[i1++];
            else
                cur = nums2[i2++];
        }
        if (len%2 == 0)
            return (last+cur)/2.0;
        else
            return double(cur);
    }
};

// way2:O(logn)
// 方法的本质是每次从联合数组中筛选剩余的k/2个值
class Solution {
public:
    vector<int> n1, n2;
    int m, n, len;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        m = n1.size();
        n = n2.size();
        len = n+m;
        // 获取数组中位数idx的技巧：
        // 【奇数】求出中位数的重复坐标
        // 【偶数】求出中位数的两个坐标
        int left = (len+1)/2;
        int right = (len+2)/2;
        int a1 = getkth(0, 0, left);
        int a2 = getkth(0, 0, right);
        return (a1 + a2) * 0.5;
    }
    int getkth(int s1, int s2, int k) {
        // 如果有任意一个指针超过数组的长度，则返回另一个数组的第k个值
        if (s1 >= m)
            return n2[s2+k-1];
        if (s2 >= n)
            return n1[s1+k-1];
        // 当k=1时，意思是当前要获取联合数组的"最小值"，则直接比较二者的大小即可
        if (k == 1)
            return n1[s1]<n2[s2]?n1[s1]:n2[s2];
        // 计算当前需要的偏移量
        int shift = k/2;
        // 此处m和n要注意-1来获得真正的最后一个值
        int p1 = min(s1+shift, m)-1;
        int p2 = min(s2+shift, n)-1;
        // 递归的寻找最小值即可
        if (n1[p1] < n2[p2]) {
            return getkth(p1+1, s2, k-(p1-s1+1));
        } else {
            return getkth(s1, p2+1, k-(p2-s2+1));
        }
    }
};