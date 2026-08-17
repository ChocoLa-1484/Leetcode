class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> mp;
        for (const int x : nums)
            mp.set(x);
        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next) {
            if (mp.test(cur->next->val)) {
                cur->next = cur->next->next;
             } else {
                cur = cur->next;
             }
        }
        return dummy.next;
    }
};