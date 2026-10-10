class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int cnt[100005] = {}, n = nums1.size(), mxn = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x = abs(nums1[i] - nums2[i]);
            cnt[x]++;
            ans += 1LL * x * x;
            mxn = max(mxn, x);
        }
        int k = k1 + k2;
        for (int i = mxn - 1, t = 0; i >= 0 && k > 0; i--) {
            t += cnt[i + 1];
            ans -= (1LL * (i + 1) * (i + 1) - 1LL * i * i) * min(k, t);
            k -= t;
        }
        return ans;
    }
};