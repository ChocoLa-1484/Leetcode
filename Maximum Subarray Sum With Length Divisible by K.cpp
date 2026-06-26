class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(k, LLONG_MAX >> 1);
        pref[0] = 0;
        long long sum = 0, MAX = LONG_LONG_MIN;
        for(int i = 1; i <= n; i++) {
            sum += nums[i - 1];
            MAX = max(MAX, sum - pref[i % k]);
            pref[i % k] = min(pref[i % k], sum); 
        }
        return MAX;
    }
};