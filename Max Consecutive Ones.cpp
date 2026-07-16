class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cur = 0;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (i == n || nums[i] != 1) {
                ans = max(cur, ans);
                cur = 0;
                continue;
            }
            cur++;
        }
        return ans;
    }
};