#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    struct ListNode {
         int val;
         struct ListNode *next;
         ListNode(int x) :
               val(x), next(NULL) {
         }
    };

    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* p1 = headA;
            ListNode* p2 = headB;
            if (!p1 || !p2)
                return NULL;
            unordered_set<ListNode*> s;
            while (p1->next) {
                s.insert(p1);
            }
            s.insert(p1);

            while (p2->next) {
                if (s.find(p2) != s.end())
                    return p2;
            }
            if (s.find(p2) != s.end())
                return p2;
            return NULL;
        }
    };

    Solution* s = new Solution();
    vector<int> nums = {2,3,4,2,6,2,5,1};
    vector<int> ans = s->maxInWindows(nums, 3);
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<' ';
    }
    return 0;
}
