class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() < s2.length())  swap(s1, s2);
        if (s1.length() + s2.length() != s3.length())   return false;
        int n = s1.length(), m = s2.length();
        bitset<101> dp;
        dp[0] = 1;
        for (int j = 0; j < m && s2[j] == s3[j]; j++) {
            dp[j + 1] = dp[j];
        }
        for (int i = 0; i < n; i++) {
            dp[0] = dp[0] && s1[i] == s3[i];
            for (int j = 0; j < m; j++) {
                dp[j + 1] = dp[j + 1] && s1[i] == s3[i + j + 1] || dp[j] && s2[j] == s3[i + j + 1];
            }
        }
        return dp[m];
    }
};