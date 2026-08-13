class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int sum = 0, ans = n + 1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            // while (sum - nums[l] >= target)
            //     sum -= nums[l++];
            // if (sum >= target)
            //     ans = min(ans, r - l + 1);
            while (sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans <= n ? ans : 0;
    }
};