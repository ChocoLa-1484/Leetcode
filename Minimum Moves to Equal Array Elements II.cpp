class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size();
        int mid = nums[n >> 1];
        int ans = 0;
        for (const int x : nums)    ans += abs(x - mid);
        return ans;
    }
};