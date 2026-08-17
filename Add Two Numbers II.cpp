class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* ans = nullptr;
        int carry = 0, x, y;
        while (!st1.empty() || !st2.empty() || carry != 0) {
            x = 0, y = 0;
            if (!st1.empty()) {
                x = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                y = st2.top();
                st2.pop();
            }
            int z = x + y + carry;
            carry = z / 10;
            ListNode* tmp = new ListNode(z % 10);
            tmp->next = ans;
            ans = tmp;
        }
        return ans;
    }
};