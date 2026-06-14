class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        dummy->next = head;
        while (prev->next && prev->next->next) {
            ListNode *l = prev->next;
            ListNode *r = l->next;

            l->next = r->next;
            r->next = l;
            prev->next = r;

            prev = l;
        }
        return dummy->next;
    }
};