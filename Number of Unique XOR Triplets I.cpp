class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        return nums.size() <= 2 ? nums.size() : 1 << (__lg(nums.size()) + 1);
    }
};