class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        auto check = [&](int t) {
            long long sum = 0;
            for (int i = n - 1; i >= 1; i--) {
                sum = max(0LL, sum + (nums[i] - t));
            }
            return (nums[0] - t + sum) <= 0;
        };
        int l = nums[0] - 1, r = ranges::max(nums);
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (check(mid) ? r : l) = mid;
        }
        return r;
    }
};

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0, s = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            s += nums[i];
            ans = max(ans, (s + i) / (i + 1));
        }
        return ans;
    }
};