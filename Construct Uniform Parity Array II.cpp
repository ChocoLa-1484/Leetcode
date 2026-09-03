class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn_odd = INT_MAX, mn_even = INT_MAX;
        for (const int x : nums1) {
            if (x & 1)  mn_odd = min(x, mn_odd);
            else    mn_even = min(x, mn_even);
        }
        if (mn_odd == INT_MAX || mn_even == INT_MAX)
            return true;
        return mn_odd < mn_even;
    }
};
