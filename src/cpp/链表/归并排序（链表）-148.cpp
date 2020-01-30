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
        // 链表的递归返回
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