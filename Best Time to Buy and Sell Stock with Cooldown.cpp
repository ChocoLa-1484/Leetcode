class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<array<int, 2>> memo(n, {INT_MIN, INT_MIN});
        auto dfs = [&](this auto&& dfs, int i, bool hold) -> int {
            if (i < 0) return hold ? INT_MIN / 2 : 0;
            int& res = memo[i][hold];
            if (res != INT_MIN) return res;
            if (hold)   return res = max(dfs(i - 1, true), dfs(i - 2, false) - prices[i]);
            return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i]);
        };
        return dfs(n - 1, false);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<array<int, 2>> dp(n + 2);
        dp[1][1] = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i + 2][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
            dp[i + 2][1] = max(dp[i + 1][1], dp[i][0] - prices[i]);
        }
        return dp.back()[0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pre0 = 0, f0 = 0, f1 = INT_MIN;
        for (const int x : prices) {
            int new_f0 = max(f0, f1 + x);
            f1 = max(f1, pre0 - x);
            pre0 = f0;
            f0 = new_f0;
        }
        return f0;
    }
};