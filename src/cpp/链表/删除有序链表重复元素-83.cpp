// easy->medium
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL)
            return NULL;
        ListNode* cur = head, *nex, *tmp;
        while (cur->next) {
            nex = cur->next;
            while (cur->val == nex->val) {
                nex = nex->next;
                if (nex == NULL) {
                    break;
                }
            }
            cur->next = nex;
            cur = cur->next;
        }
        return head;
    }
};