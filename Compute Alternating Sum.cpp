class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += (i & 1) ? -nums[i] : nums[i];
        }
        return ans;
    }
};