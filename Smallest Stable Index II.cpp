class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> r(n);
        int mn = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mn = min(nums[i], mn);
            r[i] = mn;
        }
        int mx = -1;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (mx - r[i] <= k) return i;
        }
        return -1;
    }
};