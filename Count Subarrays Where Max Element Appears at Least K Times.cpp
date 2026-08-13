class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int l = 0, n = nums.size();
        int mx = ranges::max(nums);
        int cnt = 0;
        for (const int x : nums) {
            cnt += x == mx;
            while (cnt == k)
                cnt -= nums[l++] == mx;
            ans += l;
        }
        return ans;
    }
};