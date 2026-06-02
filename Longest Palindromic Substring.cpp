class Solution {
public:
    string expand(int l, int r, string s) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--, r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string ans = "", ss = "";
        for (int i = 0; i < s.size(); i++) {
            ss = expand(i, i, s);
            if (ss.size() > ans.size()) ans = ss;
            ss = expand(i, i+1, s);
            if (ss.size() > ans.size()) ans = ss;
        }
        return ans;
    }
};

class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        pair<short, short> ans = {0, 1};
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n; i++) { // len = 2
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, 2};
            }
        }
        short maxLen = -1;
        for (int diff = 2; diff < n; diff++) { // len >= 3
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (diff > maxLen) {
                        maxLen = diff;
                        ans = {i, diff + 1};
                    }
                }
            }
        }
        string ret = s.substr(ans.first, ans.second);
        return ret;
    }
};