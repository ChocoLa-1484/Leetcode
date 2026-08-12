class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX >> 1;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])    continue;
            int s = nums[i] + nums[i + 1] + nums[i + 2];
            if (s > target) {
                if (s - target < abs(ans - target))
                    ans = s;
                break;
            }
            s = nums[i] + nums[n - 1] + nums[n - 2];
            if (s < target) {
                if (target - s < abs(ans - target))
                    ans = s;
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x == target)    return target;
                if (abs(x - target) < abs(ans - target))  
                    ans = x;
                if (x > target)
                    k--;
                else 
                    j++;
            }
        }
        return ans;
    }
};