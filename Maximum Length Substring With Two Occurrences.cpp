class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[26] = {};
        int l = 0;
        int n = s.length();
        int ans = 0;
        for (int r = 0; r < n; r++) {
            cnt[s[r] - 'a']++;
            while (cnt[s[r] - 'a'] > 2)
                cnt[s[l++] - 'a']--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};