class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto mid = middleNode(head);
        mid = reverseList(mid);
        while (mid) {
            if (head->val != mid->val)
                return false;
            head = head->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            swap(prev, head->next);
            swap(head, prev);
        }
        return prev;
    }
};