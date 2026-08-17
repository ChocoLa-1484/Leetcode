class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode dummy(INT_MAX);
        vector<ListNode*> st{ &dummy };
        auto cur = head;
        while (cur) {
            while (!st.empty() && cur->val > st.back()->val) 
                st.pop_back();
            st.back()->next = cur;
            st.push_back(cur);
            cur = cur->next;
        }
        return dummy.next;
    }
};