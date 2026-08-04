class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> st;
        int n = 0, MIN = INT_MAX, MAX = INT_MIN;
        for (const int x : nums) {
            MIN = min(MIN, x);
            MAX = max(MAX, x);
            st.set(x);
        }
        vector<int> ans;
        for (int i = MIN; i <= MAX; i++) {
            if (!st.test(i))    ans.push_back(i);
        }
        return ans;
    }
};