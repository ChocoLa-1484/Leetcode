class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int sum = 0;
        for (const int x : nums) {
            sum = min(sum + x, target);
            for (int j = sum; j >= x; j--) {
                dp[j] = max(dp[j], dp[j - x] + 1);
            }
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};