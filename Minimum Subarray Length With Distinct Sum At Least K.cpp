class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int l = 0, n = nums.size();
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            if (++cnt[nums[r]] == 1) k -= nums[r];
            while (k <= 0) {
                ans = min(ans, r - l + 1);
                if (--cnt[nums[l]] == 0) k += nums[l];
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};