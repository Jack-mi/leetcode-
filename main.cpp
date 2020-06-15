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
    string num2str(int n) {
        char str[10];
        sprintf(str, "%d", n);
        return string(str);
    }
    int findNthDigit(long n) {
        if (n==0)
            return 0;
        int start = 1;
        int digit = 1;
        long count = 9;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9*start*digit;
        }
        int number = start+(n-1)/digit;
        string real = num2str(number);
        return real[(n-1)%digit] - '0';
    }
};

int main() {
    vector<int> num = {3,30,34,5,9};
    vector<vector<int>> nn = {{1,3},{2,6},{8,10},{15,18}};
    string str = "abcabcbb";
    Solution* s = new Solution();
    cout<<s->findNthDigit(1000);
    return 0;
}
