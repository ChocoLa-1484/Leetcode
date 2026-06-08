class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode(), *r = new ListNode();
        ListNode *l_head = l, *r_head = r;
        while (head) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        r->next = nullptr;
        l->next = r_head->next;
        head = l_head->next;
        delete l_head;
        delete r_head;
        return head;
    }
};