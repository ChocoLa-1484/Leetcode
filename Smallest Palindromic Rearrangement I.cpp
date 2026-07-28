class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {};
        for (char c : s)
            cnt[c - 'a']++;
        string a = "", c = "";
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1)   c = c = string(1, 'a' + i);
            a.append(cnt[i] >> 1, 'a' + i);
        }
        string b = a;
        reverse(b.begin(), b.end());
        return a + c + b;
    }
};