#define ll long long
class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preVal(n + 1), preSum(n + 1), prePow(n + 1);
        vector<int> pow(n + 1);
        pow[0] = 1;
        for (int i = 1; i <= n; i++)
            pow[i] = (ll)pow[i - 1] * 10 % MOD;
        preVal[0] = preSum[0] = prePow[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                preVal[i + 1] = preVal[i];
                preSum[i + 1] = preSum[i];
                prePow[i + 1] = prePow[i];
                continue;
            }
            preVal[i + 1] = ((ll)preVal[i] * 10 + s[i] - '0') % MOD;
            prePow[i + 1] = prePow[i] + 1;
            preSum[i + 1] = preSum[i] + s[i] - '0';
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1] + 1;
            ans[i] = (preVal[r] - (ll)preVal[l] * pow[prePow[r] - prePow[l]] % MOD) 
                    * (preSum[r] - preSum[l]) % MOD;
            if (ans[i] < 0) ans[i] += MOD;
        }
        return ans;
    }
};