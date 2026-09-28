class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = ranges::fold_left(nums, 0, plus{});
        if (target & 1)    return false;
        target >>= 1;
        bitset<10001> dp;
        dp[0] = 1;       
        for (const int x : nums) {
            dp |= dp << x;
        }
        return dp[target];
    }
};