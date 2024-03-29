class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n+1);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = INT_MAX;
            for (int j = 1; j*j <= i; ++j) {
                f[i] = min(f[i-j*j]+1, f[i]);
            }
        }
        return f[n];
    }
};