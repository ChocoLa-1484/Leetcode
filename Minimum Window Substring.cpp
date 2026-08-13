class Solution {
public:
    string minWindow(string s, string t) {
        constexpr static int INF = -99999;
        int cnt[128] = {};
        fill(cnt, cnt + 128, INF);
        int l = 0, n = s.length();
        for (char c : t) {
            if (cnt[c] == INF) cnt[c] = 0;
            cnt[c]++;
        }
        int id = 0, len = n + 1;
        int tLen = t.length();
        for (int r = 0; r < n; r++) {
            if (cnt[s[r]] != INF) {
                if (--cnt[s[r]] >= 0) tLen--;
            }
            while (tLen == 0) {
                if (r - l + 1 < len)
                    id = l, len = r - l + 1;
                if (cnt[s[l]] != INF) {
                    if (++cnt[s[l]] > 0) tLen++;
                }
                l++;
            }
        }
        return len == n + 1 ? "" : s.substr(id, len);
    }
};