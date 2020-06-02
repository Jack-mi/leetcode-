class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* p = head->next;
        int ans = head->val;
        int i = 2;
        while (p) {
            // 第i个节点以1/i的概率被选中
            if (rand()%i + 1 == i)
                ans = p->val;
            i++;
            p = p->next;
        }
        return ans;
    }
};