class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; i++) {
            string ss = "";
            char c = s[0];
            int cnt = 1;
            for (int j = 1; j <= s.length(); j++) {
                if (j == s.length() || s[j] != c) {
                    ss += cnt + '0';
                    ss += c;
                    c = j == s.length() ? ' ' : s[j];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            s = ss;
        }
        return s;
    }
};