class Solution {
public:
    int minMoves(vector<int>& nums) {
        return ranges::max(nums) * nums.size() - ranges::fold_left(nums, 0, plus<>{});
    }
};