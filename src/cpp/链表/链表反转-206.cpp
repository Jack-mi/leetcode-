// 1.迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur(head), *pre(NULL);
        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        return head;
    }
};

// 2.递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL|| head->next == NULL)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};