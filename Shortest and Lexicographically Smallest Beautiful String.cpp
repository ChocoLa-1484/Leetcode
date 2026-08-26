class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans(101, '1');
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (s[r] == '1')    k--;
            while (k == 0) {
                int len = r - l + 1;
                if (len < ans.length()) {
                    ans = s.substr(l, r - l + 1);
                } else if (len == ans.length()){
                    ans = min(ans, s.substr(l, r - l + 1));
                }
                if (s[l++] == '1')  k++;
            }
        }
        return ans.length() == 101 ? "" : ans;
    }
};