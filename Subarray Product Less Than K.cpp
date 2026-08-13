class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int l = 0, prod = 1;
        int ans = 0;
        for (int r = 0; r < n; r++) {
            prod *= nums[r];
            while (prod >= k) 
                prod /= nums[l++];
            ans += r - l + 1;
        }
        return ans;
    }
};