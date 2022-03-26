#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <algorithm>
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
    ListNode(int x, ListNode* nxt = NULL) : val(x), next(nxt) {}
};

struct DlinkNode {
    int key, value;
    DlinkNode* prev, *next;
    DlinkNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkNode(int k, int v):key(k), value(v), prev(nullptr), next(nullptr) {}
};

class Solution {
public:
    // Equivalent to finding the longest subarray which contains k 0s.
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 0) sum++;
            while (sum > k) {
                if (nums[l] == 0) sum--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> arr1 = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> arr2 = {5};
    vector<vector<char>> g = {{'a'}, {'a'}};
    string str1 = "aa";
    string str2 = "aa";
//    cout<<"hello world!"<<endl;
    cout<<s->longestOnes(arr1, 2);
    return 0;
}


