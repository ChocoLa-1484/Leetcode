class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int dif = nums[i] + nums[j] + nums[k] - target;
                if (abs(dif) < abs(ans)) 
                    ans = dif;
                if (dif < 0)    j++;
                else if (dif > 0)    k--;
                else    return target;
                
            }
        }
        return (ans + target);
    }
};