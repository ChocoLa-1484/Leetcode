class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto end = nums.begin();
        for (const int x : nums) {
            auto it = lower_bound(nums.begin(), end, x);
            *it = x;
            if (it == end)  end++;
        }
        return end - nums.begin();
    }
};