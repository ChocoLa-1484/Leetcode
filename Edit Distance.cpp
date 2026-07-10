class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> dp(m + 1);
        ranges::iota(dp, 0);
        for(int i = 1; i <= n; i++){
            int pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= m; j++){
                int tmp = dp[j];
                if(word1[i - 1] == word2[j - 1]) dp[j] = pre;
                else    dp[j] = min({dp[j], dp[j - 1], pre}) + 1;
                pre = tmp;
            }
        }
        return dp[m];
    }
};