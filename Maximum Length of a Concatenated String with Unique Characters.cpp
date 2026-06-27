class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        dfs(0, arr, 0);
        return ans;
    }
    void dfs(int now, vector<string>& v, int mask) {
        if (now == v.size()) {
            ans = max(ans, __builtin_popcount(mask));
            return;
        }
        dfs(now + 1, v, mask);
        int b = 0;
        for (char c : v[now]) {
            int bit = 1 << (c - 'a');
            if ((b & bit) || (mask & bit))
                return;
            b |= bit;
        }
        dfs(now + 1, v, mask | b);
    }
};