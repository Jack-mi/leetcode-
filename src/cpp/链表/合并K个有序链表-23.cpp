// way-1：时间复杂度O(nk)
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        ListNode* H = new ListNode(0);
        ListNode* head = H;

        int len = lists.size();
        if(len == 0)
            return H->next;

        vector<int> tend(len);
        int left = 0;
        for(int i = 0;i < len;i++) {
            if(!lists[i]) {
                tend[i] = 1;
            } else {
                tend[i] = 0;
                left ++;
            }
        }
        if(left == 0)
            return H->next;

        while(left != 1) {
            int curm = INT_MAX;
            int curi = 0;
            for (int i = 0; i < len; i++) {
                if (!lists[i])
                    continue;
                if (lists[i]->val < curm) {
                    curm = lists[i]->val;
                    curi = i;
                }
            }
            ListNode* curl = lists[curi];
            head->next = curl;
            head = head->next;
            lists[curi] = lists[curi]->next;
            if(!lists[curi]) {
                left--;
                tend[curi] = 1;
            }
        }

        for(int i = 0;i < len;i++) {
            if(tend[i] == 0) {
                ListNode* p = lists[i];
                while(p) {
                    head->next = p;
                    head = head->next;
                    p = p->next;
                }
                break;
            }
        }
        return H->next;
    }
};