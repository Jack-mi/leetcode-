class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        int len1, len2;
        ListNode* p1(l1), *p2(l2);
        ListNode* q1(l1), *q2(l2);
        while (p1) {
            len1++;
            p1 = p1->next;
        }
        while (p2) {
            len2++;
            p2 = p2->next;
        }
        int remainder = 0;
        while (q1 && q2) {
            int sum = q1->val + q2->val + remainder;
            if (sum < 10) {
                remainder = 0;
                q1->val = sum;
                q2->val = sum;
            } else {
                remainder = 1;
                q1->val = sum-10;
                q2->val = sum-10;
            }
            q1 = q1->next;
            q2 = q2->next;
        }
        while (q1) {
            int sum = q1->val + remainder;
            if (sum < 10) {
                remainder = 0;
                q1->val = sum;
            } else {
                remainder = 1;
                q1->val = sum-10;
            }
            q1 = q1->next;
            ans = l1;
        }
        while (q2) {
            int sum = q2->val + remainder;
            if (sum < 10) {
                remainder = 0;
                q2->val = sum;
            } else {
                remainder = 1;
                q2->val = sum-10;
            }
            q2 = q2->next;
            ans = l2;
        }
        if (remainder) {
            ListNode* last = new ListNode(1);
            last->next = NULL;
            ListNode* f = ans;
            while (f->next)
                f = f->next;
            f->next = last;
        }
        return ans;
    }
};