class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](const char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += isVowel(s[i]);
        int ans = cnt, n = s.length();
        for (int i = k; i < n; i++) {
            cnt += isVowel(s[i]) - isVowel(s[i - k]);
            ans = max(ans, cnt);
            if (ans == k)   break;
        }
        return ans;
    }
};