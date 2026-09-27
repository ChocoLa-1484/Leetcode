static constexpr int MX = 10001;
int dp[MX];

auto init = [] {
    ranges::fill(dp, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i < MX; i++) {
        for (int j = i * i; j < MX; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }
    return 0;
}();

class Solution {
public:
    int numSquares(int n) {
        return dp[n];
    }
};