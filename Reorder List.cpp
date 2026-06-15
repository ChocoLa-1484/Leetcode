class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *cur = slow->next;
        slow->next = nullptr;

        ListNode* dummy2 = nullptr;
        while (cur) {
            swap(cur->next, dummy2);
            swap(dummy2, cur);
        }
        ListNode *dummy1 = head;

        ListNode *next1, *next2;
        while (dummy2) {
            next1 = dummy1->next;
            next2 = dummy2->next;
            dummy1->next = dummy2;
            dummy2->next = next1;
            dummy1 = next1;
            dummy2 = next2;
        }
    }
};