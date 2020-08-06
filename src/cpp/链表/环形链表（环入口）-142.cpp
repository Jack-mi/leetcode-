class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (!fast || !fast->next)
                return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};