class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(ranges::min(nums), ranges::max(nums));
    }
};