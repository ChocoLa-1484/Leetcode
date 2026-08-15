class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int t = 0;
        bool zero = true;
        for (int x : nums) {
            t ^= x;
            if (x > 0)
                zero = false;
        }
        if (t > 0)  return n;
        return zero ? 0 : n - 1;
    }
};