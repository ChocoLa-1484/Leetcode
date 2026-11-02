class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = ranges::min(nums), ans = 0;
        for (const int x : nums) {
            ans += x - mn;
        }
        return ans;
    }
};