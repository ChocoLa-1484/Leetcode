class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        if (!cur)   return {-1, -1};
        ListNode* next = cur->next;
        int l = 0, r = 0, now = 1;
        int ans1 = INT_MAX, ans2 = -1;
        while (next) {
            if ((cur->val > prev->val && cur->val > next->val) ||
                (cur->val < prev->val && cur->val < next->val)) {
                if (l == 0) {
                    l = r = now;
                } else {
                    ans1 = min(ans1, now - r);
                    ans2 = now - l;
                    r = now;
                }
            }
            prev = prev->next;
            cur = cur->next;
            next = next->next;
            now++;
        }
        if (ans1 == INT_MAX)    return {-1, -1};
        return {ans1, ans2};
    }
};