class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = ranges::fold_left(nums, 0, plus{}) - abs(target);
        if (s < 0 || s & 1) return 0;
        int m = s / 2;
        int n = nums.size();
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = m; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        return dp.back();
    }
};