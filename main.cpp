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
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int num = 0;
        for (auto n:nums) {
            if (n == candidate)
                num++;
            else {
                if (--num < 0) {
                    candidate = n;
                    num = 0;
                }
            }
        }
        return candidate;
    }
};

int main() {
    vector<int> num = {1,2,3,0,2};
    string ss = "abc";
    Solution* s = new Solution();
    s->permutation(ss);
    return 0;
}
