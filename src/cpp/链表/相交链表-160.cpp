class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        if (!p1 || !p2)
            return NULL;
        int flag1 = 0, flag2 = 0;
        while (p1 != p2) {
            p1 = p1->next;
            if (flag1 == 0 && p1 == NULL) {
                flag1 = 1;
                p1 = headB;
            }
            p2 = p2->next;
            if (flag2 == 0 && p2 == NULL) {
                flag2 = 1;
                p2 = headA;
            }
        }
        if (p1 == p2)
            return p1;
        return NULL;
    }
};