class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        bitset<10001> st;
        vector<int> ans(2);
        for (int i : nums) {
            if (st.test(i))     ans[0] = i;
            st.set(i);
        }
        for (int i = 1; i <= n; i++) {
            if (!st.test(i))    ans[1] = i;
        }
        return ans;
    }
};