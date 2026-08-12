class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        ranges::sort(nums);
        int i = 0, j = n - 1, ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                i++;
            } else {
                j--
            }
        }
        return ans;
    }
};