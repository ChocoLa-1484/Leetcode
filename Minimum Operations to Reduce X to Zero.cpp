class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = reduce(nums.begin(), nums.end()) - x;
        if (target < 0) return -1;
        int n = nums.size();
        int sum = 0;
        int l = 0, ans = -1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target)
                sum -= nums[l++];
            if (sum == target)
                ans = max(ans, r - l + 1);
        }
        return ans == -1 ? -1 : n - ans;
    }
};