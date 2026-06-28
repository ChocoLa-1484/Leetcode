class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1, 0);
        for (int i : arr)
            cnt[min(i, n)]++;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = min(ans + cnt[i], i);
        }
        return ans;
    }
};