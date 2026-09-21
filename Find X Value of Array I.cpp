class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();        
        vector<long long> ans(k), dp(k), nxt(k);
        for (const int num : nums) {
            ranges::fill(nxt, 0);
            int x = num % k;
            nxt[x] = 1;
            ans[x]++;
            for (int i = 0; i < k; i++) {
                if (dp[i] == 0) continue;
                int j = i * x % k;
                nxt[j] += dp[i];
                ans[j] += dp[i];
            }
            dp.swap(nxt);
        }
        return ans;
    }
};