class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0, l = 0;
        for (auto i : nums) {
            sum += i;
        }
        for (int i = 0; i < nums.size(); i++) {
            l += nums[i];
            if (sum - l == l - nums[i]) {
                return i; 
            }
        }
        return -1;
    }
};