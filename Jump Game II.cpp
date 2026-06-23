class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            end = max(end, i + nums[i]);
            if (i == start) {
                ans++;
                start = end;
            }
        }
        return ans;
    }
};