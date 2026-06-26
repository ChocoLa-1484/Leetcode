class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int freq[100001] = {};
        long long ans = 0;
        freq[0] = 1;
        int cur = 0;
        for (int i : nums) {
            cur += (i % modulo == k);
            if (cur < k) {
                freq[cur]++;
                continue;
            }
            ans += freq[(cur - k) % modulo];
            freq[cur % modulo]++;
        }
        return ans;
    }
};