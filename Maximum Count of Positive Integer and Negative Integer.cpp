class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        auto l = n - (lower_bound(nums.begin(), nums.end(), 1) - nums.begin());
        auto r = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return max(l, r);
    }
};