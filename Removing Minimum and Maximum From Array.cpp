class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        const auto [mn_it, mx_it] = ranges::minmax_element(nums);
        const auto [i, j] = minmax(mn_it - nums.begin(), mx_it - nums.begin());
        return min({j + 1, n - i, n - (j - i) + 1});
    }
};