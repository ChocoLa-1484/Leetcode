class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), ans = n + 1;
        vector<int> dp(n + 1, n + 1);
        for (int i = 0, j = 0, sum = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target)
                sum -= arr[j++];
            dp[i + 1] = dp[i];
            if (sum == target) {
                int len = i - j + 1;
                ans = min(ans, len + dp[j]);
                dp[i + 1] = min(dp[i], len);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};