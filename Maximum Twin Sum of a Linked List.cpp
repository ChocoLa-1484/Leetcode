class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head, *prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            swap(slow->next, prev);
            swap(prev, slow);
        }
        int ans = -1;
        while (slow) {
            ans = max(ans, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return ans;
    }
};