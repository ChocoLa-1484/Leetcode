class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        auto is_blue = [&](int i) {
            int end = nums.back();
            if (nums[i] > end) {
                return target > end && nums[i] >= target;
            } else {
                return target > end || nums[i] >= target;
            }
        };
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (is_blue(mid) ? r : l) = mid;
        }
        if (r == n || nums[r] != target)    return -1;
        return r;
    }
};