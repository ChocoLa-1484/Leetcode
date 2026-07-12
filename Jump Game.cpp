class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MAX = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (MAX < i) return false;
            MAX = max(MAX, i + nums[i]);
            if (MAX >= nums.size() - 1)   return true;
        }
        return true;
    }
};