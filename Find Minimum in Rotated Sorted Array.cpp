class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (nums[mid] < nums.back() ? r : l) = mid;
        }
        return nums[r];
    }
};