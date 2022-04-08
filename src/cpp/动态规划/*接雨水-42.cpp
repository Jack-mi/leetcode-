class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 1||len == 0) {
            return 0;
        }
        int ans = 0;
        int leftMax[len], rightMax[len];
        leftMax[0] = height[0];
        rightMax[len-1] = height[len-1];
        for (int i = 1; i < len; ++i) {
            leftMax[i] = max(height[i], leftMax[i-1]);
        }
        for (int i = len-2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        for (int i = 0; i < len; ++i) {
            ans += min(rightMax[i], leftMax[i])-height[i];
        }
        return ans;
    }
};
