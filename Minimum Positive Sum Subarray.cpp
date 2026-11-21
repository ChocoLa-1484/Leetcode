class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int start = 0; start <= n - l; ++start) {
            int cur = 0;
            for (int i = 0; i < r && start + i < n; ++i) {
                cur += nums[start + i];
                if (i >= l - 1 && cur > 0)  ans = min(ans, cur);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};