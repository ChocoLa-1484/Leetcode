class Solution {
public:
    int rob1(vector<int>& nums, int start, int end) {
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            f0 = exchange(f1, max(f0 + nums[i], f1));
        }
        return f1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));
    }
};