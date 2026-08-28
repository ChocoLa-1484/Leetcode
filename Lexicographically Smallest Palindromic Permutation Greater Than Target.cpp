class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int cnt[26] = {};
        for (const char c : s)  cnt[c - 'a']++;
        
        string center;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1) {
                if (!center.empty()) return "";
                center += (i + 'a');
                cnt[i]--;
            }
            cnt[i] >>= 1;
        }
        int n = s.length(), hf = n >> 1, bad = 0;
        for (int i = 0; i < hf; i++) {
            if (cnt[target[i] - 'a']-- == 0)
                bad++;
        }
        if (bad == 0) {
            string head = target.substr(0, hf);
            string tail = center + string(head.rbegin(), head.rend());
            if (tail > target.substr(hf))
                return head + tail;
        }
        for (int i = hf - 1; i >= 0; i--) {
            int x = target[i] - 'a';
            if (++cnt[x] == 0)  bad--;
            if (bad > 0)    continue;

            for (int j = x + 1; j < 26; j++) {
                if (!cnt[j]) continue;
                cnt[j]--;
                string head = target.substr(0, i) + string(1, j + 'a');
                for (int ch = 0; ch < 26; ch++)
                    head.append(cnt[ch], 'a' + ch);
                return head + center + string(head.rbegin(), head.rend());
            }
        }
        return "";
    }
};