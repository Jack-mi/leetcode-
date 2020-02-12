// easy 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode* fast(head), *slow(head);
        while (fast->next && slow->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == NULL)
                return false;
            if (fast->val == slow->val)
                return true;
        }
        return false;
    }
};