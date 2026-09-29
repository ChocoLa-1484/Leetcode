class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        vector<int> dp(m + 1, INT_MIN);
        for (const int x : nums1)
            for (int j = 0, pre = 0; j < m; j++) 
                pre = exchange(dp[j + 1], max(max(pre, 0) + x * nums2[j], max(dp[j + 1], dp[j])));
        return dp[m];
    }
};