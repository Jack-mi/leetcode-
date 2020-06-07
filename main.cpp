#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <cmath>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0 || arr.size() == 0)
            return ans;
        priority_queue<int> Q;
        for (int i = 0; i < k; ++i)
            Q.push(arr[i]);
        for (int i = k; i < ans.size(); ++i) {
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

int main() {
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nn = {1,3,5,2,0};
    string ss = "abc";
    Solution* s = new Solution();
    s->getLeastNumbers(nn, 2);
    return 0;
}
