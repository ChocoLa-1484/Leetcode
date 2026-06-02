class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* cur = result;
        int carry = 0;
        while (l1 || l2  || carry) {
            int x = l1 ? l1->val : 0, y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        ListNode* ans = result->next;
        delete result;
        return ans;
    }
};