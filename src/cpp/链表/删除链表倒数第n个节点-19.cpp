class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *pre(head);
        ListNode* slow = head;
        if (!head)
            return head;
        while (n--)
            fast = fast->next;
        if (!fast)
            return head->next;

        int cnt = 0;
        while (slow && fast) {
            if (cnt) {
                pre = pre->next;
            } else {
                cnt ++;
                slow = slow->next;
                fast = fast->next;
                continue;
            }
            slow = slow->next;
            fast = fast->next;
        }
        pre->next = slow->next;
        return head;
    }
};