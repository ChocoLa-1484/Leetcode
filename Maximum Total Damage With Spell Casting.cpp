class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        ranges::sort(power);
        int n = power.size();
        long long dp[100001] = {}, MAX = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (power[i] == power[max(0, i - 1)])
                dp[i + 1] = power[i] + dp[i];
            else {
                while (power[i] - power[j] > 2)
                    MAX = max(MAX, dp[++j]);
                dp[i + 1] = power[i] + MAX;
            }
        }
        return *max_element(begin(dp), begin(dp) + n + 1);
    }
};