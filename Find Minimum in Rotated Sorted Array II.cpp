class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == nums[r])
                r--;
            else
                (nums[mid] < nums[r] ? r : l) = mid;
        }
        return nums[r];
    }
};