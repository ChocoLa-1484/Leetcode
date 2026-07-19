class Solution {
public:
    string maskPII(string s) {
        auto it = find(s.begin(), s.end(), '@');
        int n = s.length();
        string ans = "";
        ans.reserve(n);
        if (it != s.end()) {
            int pos = it - s.begin();
            string s1 = s.substr(0, pos), s2 = s.substr(pos);
            transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
            cout << s1 << " " << s2;
            ans = string(1, tolower(s1[0])) + "*****" + 
                  string(1, tolower(s1.back())) + s2;
        } else {
            int cnt = 0;
            string ss = "";
            for (int i = n - 1; i >= 0; i--) {
                if ('0' <= s[i] && s[i] <= '9') {
                    cnt++;
                    if (ss.length() < 4)   ss += s[i];
                }
            }
            reverse(ss.begin(), ss.end());
            cnt -= 10;
            ans = "***-***-" + ss;
            if (cnt > 0) {
                string s1 = "+";
                for (int i = 0; i < cnt; i++)
                    s1 += '*';
                ans = s1 + "-" + ans;
            }
        }
        return ans;
    }
};