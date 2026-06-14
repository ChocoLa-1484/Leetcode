class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)  return nullptr;
        int diff = 1;
        int n = lists.size();
        while (diff < n) {
            for (int i = 0; i + diff < n; i += (diff << 1)) {
                lists[i] = merge(lists[i], lists[i + diff]);
            }
            diff <<= 1;
        }
        return lists[0];
    }
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode head(0);
        ListNode *dummy = &head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        dummy->next = list1 ? list1 : list2;
        return head.next;
    }
};