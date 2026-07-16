class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = -1, n = nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            pre[i] = gcd(mx, nums[i]);
        }
        ranges::sort(pre);
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(pre[i], pre[n - i - 1]);
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();