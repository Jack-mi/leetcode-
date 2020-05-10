#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
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

class CQueue {
public:
    stack<int> p, q;
    CQueue() {}

    void appendTail(int value) {
        p.push(value);
    }

    int deleteHead() {
        if (p.empty())
            return -1;
        while (!p.empty()) {
            int x = p.top();
            p.pop();
            q.push(x);
        }
        int ans = q.top();
        q.pop();
        while (!q.empty()) {
            int x = q.top();
            q.pop();
            p.push(x);
        }
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
int main() {
    vector<vector<int>> matrix = {
            {1, 1}
//            {1,   4,  7, 11, 15},
//            {2,   5,  8, 12, 19},
//            {3,   6,  9, 16, 22},
//            {10, 13, 14, 17, 24},
//            {18, 21, 23, 26, 30}
    };
    Solution* s = new Solution();
    cout<<s->replaceSpace("We are happy.");
    return 0;
}















