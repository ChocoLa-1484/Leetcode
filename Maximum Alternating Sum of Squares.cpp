class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const int n = nums.size(), hf = n / 2;
        ranges::nth_element(nums, nums.begin() + hf, [](const int& a, const int& b) {
            return abs(a) > abs(b);
        });
        long long ans = 0;
        for (int i = 0; i < hf; i++) {
            ans += nums[i] * nums[i];
            ans -= nums[n - i - 1] * nums[n - i - 1];
        }
        if (n & 1)  ans += nums[n / 2] * nums[n / 2];
        return ans;
    }
};