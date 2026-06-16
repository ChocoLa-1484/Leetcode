class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1, x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != x) {
                nums[index++] = nums[i];
                x = nums[i];
            }
        }
        return index;
    }
};