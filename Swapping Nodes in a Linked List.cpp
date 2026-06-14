class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *kthNode = head;
        for (int i = 1; i < k; i++, kthNode = kthNode->next) {}
        ListNode *slow = head, *fast = kthNode;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        swap(kthNode->val, slow->val);
        return head;
    }
};