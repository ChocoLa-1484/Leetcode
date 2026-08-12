class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        ranges::sort(nums);
        int n = nums.size(), ans = 0;
        for (int i = n - 1; i >= 2; i--) {
            int t = nums[i];
            if (nums[i - 2] + nums[i - 1] <= t)  continue;
            if (nums[0] + nums[1] > t) {
                ans += i * (i - 1) >> 1;
                continue;
            }
            int j = 0, k = i - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum > t) {
                    ans += k - j;
                    k--;
                } else {
                    j++;
                }   
            }
        }
        return ans;
    }
};