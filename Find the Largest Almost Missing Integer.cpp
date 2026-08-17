class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            int cnt[51] = {};
            for (const int x : nums)
                cnt[x]++;
            for (int i = 50; i >= 0; i--) {
                if (cnt[i] == 1)    return i;
            }
            return -1;
        }
        if (n == k) return ranges::max(nums);
        int a1 = nums[0], a2 = nums.back();
        if (a1 == a2)   return -1;
        bool b1 = false, b2 = false;
        for (int i = 1; i < n - 1; i++){
            if (nums[i] == a1)    b1 = true;
            if (nums[i] == a2)    b2 = true;
            if (b1 && b2) break;
        }
        return max(b1 ? -1 : a1, b2 ? -1 : a2);
    }
};