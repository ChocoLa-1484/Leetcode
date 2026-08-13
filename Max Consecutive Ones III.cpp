class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int cnt = 0;
        int l = 0, n = nums.size();
        int ans = 0;
        for (int r = 0; r < n; r++) {
            cnt += !nums[r];
            while (cnt > k)
                cnt -= !nums[l++];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};