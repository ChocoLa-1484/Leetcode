class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (int i : nums) {
            sum = max(i, sum + i);
            ans = max(sum, ans);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, ans = INT_MIN, sum = 0;
        for (int i : nums) {
            sum += i;
            ans = max(sum - l, ans);
            l = min(l, sum);
        }
        return ans;
    }
};