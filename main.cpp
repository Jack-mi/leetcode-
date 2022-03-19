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
    int lengthOfLongestSubstring(string s) {

    }
};

int main() {
    Solution* s = new Solution();
    vector<int> arr1 = {1,12,-5,-6,50,3};
    vector<int> arr2 = {5};
    vector<vector<char>> g = {{'a'}, {'a'}};
    string str = "aaa";
//    cout<<"hello world!"<<endl;
    cout<<s->findMaxAverage(arr1, 4)<<endl;
    return 0;
}


