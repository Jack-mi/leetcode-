class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0 || arr.size() == 0)
            return ans;
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i)
            Q.push(arr[i]);
        for (int i = k; i < arr.size(); ++i) {
            if (Q.top() > arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            ans.push_back(Q.top());
            Q.pop();
        }
        return ans;
    }
};
