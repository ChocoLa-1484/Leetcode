class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), k = nums[0];
        bool inc = true, dec = true;
        for (int i = 0; i < n; ++i) {
            inc &= nums[i] == (k + i) % n;
            dec &= nums[i] == (k - i + n) % n;
        }
        int ans = INT_MAX;
        if (inc) ans = min({ans, (n - k) % n, k + 2});
        if (dec) ans = min({ans, n - k, k + 2});
        return ans == INT_MAX ? -1 : ans;
    }
};