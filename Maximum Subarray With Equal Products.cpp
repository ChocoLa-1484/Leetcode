class Solution {
public:
    int maxLength(vector<int>& nums) {
        int l = 0, n = ssize(nums), prod = 1;
        int ans = 2;
        for (int r = 0; r < n; ++r) {
            int x = nums[r];
            while (gcd(prod, x) > 1)
                prod /= nums[l++];
            prod *= x;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};