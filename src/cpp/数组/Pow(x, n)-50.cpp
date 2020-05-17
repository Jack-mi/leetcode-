class Solution {
public:
    double myPow(double x, int n) {
        long double ans = 1;
        // 题目中会把n赋值到很大，超出32位
        long i = n;
        if (i < 0) {
            x = 1.0/x;
            i *= -1;
        }
        // 快速幂，将10进制转换为2进制
        while (i) {
            if (i&1) {
                ans *= x;
            }
            x *= x;
            i >>= 1;
        }
        return ans;
    }
};

// 题解：https://leetcode-cn.com/problems/powx-n/solution/50-powx-n-kuai-su-mi-qing-xi-tu-jie-by-jyd/