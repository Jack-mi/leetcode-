#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

int main() {
    struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
    };
    class Solution {
    public:
        ListNode* Merge(ListNode* l1, ListNode* l2) {
            ListNode* ptr = new ListNode(0);
            ListNode* start = ptr;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    ptr->next = l1;
                    l1 = l1->next;
                } else {
                    ptr->next = l2;
                    l2 = l2->next;
                }
                ptr = ptr->next;
            }
            if (l1) {
                ptr->next = l1;
            } else {
                ptr->next = l2;
            }
            return start->next;
        }
        ListNode* sortList(ListNode* head) {
            if (head == NULL || head->next == NULL)
                return head;
            ListNode* slow = head , *fast = head;
            // 快慢指针遍历mid和end
            while (fast->next && fast->next->next) {
                slow = fast->next;
                fast = fast->next->next;
            }
            ListNode* right = slow->next;
            slow->next = NULL;
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(right);
            ListNode* res = Merge(l1, l2);
            return res;
        }
    };
    return 0;
}
