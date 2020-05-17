class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        while (k--) {
            q = q->next;
        }
        while (q) {
            q = q->next;
            p = p->next;
        }
        return p;
    }
};