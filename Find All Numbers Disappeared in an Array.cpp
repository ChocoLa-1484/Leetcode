class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        bitset<100001> st;
        vector<int> ans;
        int n = nums.size();
        for (int i : nums)
            st.set(i);
        for (int i = 1; i <= n; i++) 
            if (!st.test(i))
                ans.emplace_back(i);
        return ans;
    }
};