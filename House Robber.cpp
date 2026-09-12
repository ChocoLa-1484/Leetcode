class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for (const int x : nums) {
            f0 = exchange(f1, max(f1, f0 + x));
        }
        return f1;
    }
};