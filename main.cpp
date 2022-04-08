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
#include <sstream>

using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* nxt = NULL) : val(x), next(nxt) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

struct DlinkNode {
    int key, value;
    DlinkNode* prev, *next;
    DlinkNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DlinkNode(int k, int v):key(k), value(v), prev(nullptr), next(nullptr) {}
};



int main() {
    Solution* s = new Solution();
    vector<int> arr1 = {2,3,2};
    vector<int> arr2 = {5};
    vector<vector<char>> g = {{'a'}, {'a'}};
    vector<vector<int>> aa = {{1,3},{0,2},{1,3},{0,2}};
    string str1 = "ab";
    string str2 = "ba";
    cout<<s->rob(arr1);
    return 0;
}


