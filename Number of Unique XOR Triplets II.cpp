class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        constexpr int MAXN = 2048;
        vector<int> u_nums;
        bitset<MAXN> seen;
        for (int x : nums) {
            if (!seen.test(x)) {
                seen.set(x);
                u_nums.emplace_back(x);
            }
        }
        int n = u_nums.size();
        bitset<MAXN> two, three;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                two.set(u_nums[i] ^ u_nums[j]);
        for (int i = 0; i < MAXN; i++) {
            if (!two.test(i))   continue;
            for (int j : u_nums)
                three.set(i ^ j);
        }
        return three.count();
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();