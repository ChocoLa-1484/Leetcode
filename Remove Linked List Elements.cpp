class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)  return nullptr;
        ListNode *prev = new ListNode(0), *dummy = prev;
        prev->next = head;
        while (prev->next) {
            if (prev->next->val == val) prev->next = prev->next->next;
            else    prev = prev->next;
        }
        return dummy->next;
    }
};