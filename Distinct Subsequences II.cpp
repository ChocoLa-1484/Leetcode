class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        long long ans = 0;
        int cnt[26] = {};
        for (const char c : s) {
            ans = (ans - exchange(cnt[c - 'a'], ans + 1) + ans + 1 + MOD) % MOD;
        }
        return ans;
    }
};