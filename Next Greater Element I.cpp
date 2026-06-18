class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> st;
        unordered_map<int, int> mp;
        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.back() <= nums2[i])
                st.pop_back();
            mp[nums2[i]] = st.empty() ? -1 : st.back();
            st.push_back(nums2[i]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = mp[nums1[i]];
        return ans;
    }
};