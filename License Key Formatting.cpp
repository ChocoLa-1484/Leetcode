class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        string ans = "";
        ans.reserve(n);
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '-')    continue;
            ans += toupper(s[i]);
            if (++cur == k) {
                ans += '-';
                cur = 0;
            }
        }
        if (!ans.empty() && ans.back() == '-')  ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};