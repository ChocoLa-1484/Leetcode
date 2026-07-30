class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (const char c : word)
            cnt[c - 'a']++;
        ranges::sort(cnt, greater{});
        int ans = 0, x = 0, y = 1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) break;
            ans += (i / 8 + 1) * cnt[i];
        }
        return ans;
    }
};