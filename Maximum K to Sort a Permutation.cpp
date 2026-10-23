class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int mask = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)   mask &= i;
            if (mask == 0)  return 0;
        }
        return max(mask, 0);
    }
};