#define pii pair<int, int> 
class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<pii> dp(n + 1, {-1, 0});
        for (int i = n - 1; i >= 0; i--) {
            vector<pii> curDp(n + 1, {-1, 0});
            for (int j = n - 1; j >= 0; j--) {
                char c = board[i][j];
                if (c == 'X')   continue;
                if (c == 'S') {
                    curDp[j] = {0, 1};
                    continue;
                }
                int Max = max({dp[j].first, dp[j + 1].first, curDp[j + 1].first});
                long long w = 0;
                if (Max == -1)  continue;
                if (Max == dp[j].first) w += dp[j].second;
                if (Max == dp[j + 1].first) w += dp[j + 1].second;
                if (Max == curDp[j + 1].first)  w += curDp[j + 1].second;
                int val = (c == 'E') ? 0 : c - '0';
                curDp[j] = {Max + val, w % MOD};
            }
            dp = curDp;
        }
        if (dp[0].first == -1)    return {0, 0};
        return {dp[0].first, dp[0].second};
    }
};