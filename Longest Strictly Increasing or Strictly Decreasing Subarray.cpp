class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, inc = 1, dec = 1;
        for (auto [a, b] : views::pairwise(nums)) {
            inc = a < b ? inc + 1 : 1;
            dec = a > b ? dec + 1 : 1;
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};