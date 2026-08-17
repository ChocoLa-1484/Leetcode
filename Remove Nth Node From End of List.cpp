class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        auto right = dummy;
        for (int i = 0; i < n; i++) {
            right = right->next;
        }
        auto left = dummy;
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};