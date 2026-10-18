class Solution {
public:
    constexpr static uint64_t MASK = (1ULL << 17) - 1;
    constexpr static uint64_t VIS = 1ULL << 63;
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<uint64_t> v(n);
        for (int i = 0; i < n; ++i) {
            int s = 0, x = nums[i];
            while (x) {
                s += x % 10;
                x /= 10;
            }
            v[i] = (static_cast<uint64_t>(s) << 47) | (static_cast<uint64_t>(nums[i]) << 17) | i;
        }
        ranges::sort(v);
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (v[i] & VIS) continue;
            --ans;
            for (int j = i; !(v[j] & VIS);) {
                int next = v[j] & MASK;
                v[j] |= VIS;
                j = next;
            }
        }
        return ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 'c';
}();