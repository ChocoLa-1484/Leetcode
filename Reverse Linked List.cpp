class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while (head) {
            swap(head->next, prev);
            swap(prev, head);
        }
        return prev;
    }
};