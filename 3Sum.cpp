class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)    j++;
                else if (sum > 0)    k--;
                else {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    ans.push_back(tmp);
                    j++;
                    while (nums[j] == nums[j - 1] && j < k) j++;
                }
            }
        }
        return ans;
    }
};