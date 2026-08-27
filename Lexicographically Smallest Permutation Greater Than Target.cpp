class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        int n = s.length();
        for (const char c : s)  cnt[c - 'a']++;
        string ans;
        for (int i = 0; i < n - 1; i++) {
            if (!cnt[target[i] - 'a'])  break;
            ans += target[i];
            cnt[target[i] - 'a']--;
        }
        for (int i = ans.length(); i >= 0; i--) {
            if (i < ans.length()) {
                cnt[ans[i] - 'a']++;
                ans.pop_back();
            }
            int x = target[i] - 'a';
            for (int j = x + 1; j < 26; j++) {
                if (!cnt[j]) continue;
                ans += char('a' + j);
                cnt[j]--;
                for (int ch = 0; ch < 26; ch++)
                    ans.append(cnt[ch], char('a' + ch));
                return ans;
            }
        }
        return "";
    }
};