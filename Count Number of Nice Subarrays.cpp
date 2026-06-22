class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[50001] = {};
        cnt[0] = 1;
        int l = 0, MAX = -1;
        for (int i = 0; i < n; i++) {
            l += nums[i] & 1;
            cnt[l]++;
            MAX = max(l, MAX);
        }
        int sum = 0;
        for (int i = 0; i + k <= MAX; i++) {
            sum += cnt[i + k] * cnt[i];
        }
        return sum;
    }
};
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            k -= nums[i] & 1;
            while (k < 0) {
                k += nums[j++] & 1;
            }
            ans += i - j + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
