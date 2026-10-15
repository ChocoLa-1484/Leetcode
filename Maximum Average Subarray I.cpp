class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int ans = sum, n = nums.size();
        for (int i = k; i < n; i++) {
            sum -= nums[i - k] - nums[i];
            ans = max(ans, sum);
        }
        return (double)ans / k;
    }
};