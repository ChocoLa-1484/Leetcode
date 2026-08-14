class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            ans += r - l;
        }
        return ans;
    }
};

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long ans = 0;
        int n = nums.size();
        int l = n, r = n;
        for (int j = 0; j < n; j++) {
            while (r && nums[j] + nums[r - 1] > upper)
                r--;
            while (l && nums[j] + nums[l - 1] >= lower)
                l--;
            ans += min(r, j) - min(l, j);
        }
        return ans;
    }
};

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        int n = nums.size();
        auto count = [&](int upper) {
            long long res = 0;
            int j = n - 1;
            for (int i = 0; i < n; i++) {
                while (i < j && nums[i] + nums[j] > upper)
                    j--;
                if (i == j) break;
                res += j - i;
            }
            return res;
        };
        return count(upper) - count(lower - 1);
    }
};