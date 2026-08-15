class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (nums[mid] > nums[mid + 1] ? r : l) = mid;
        }
        return r;
    }
};