static constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> born(n + 2, -1);
        for (int i = 0; i < n; ++i) born[nums[i]] = i;

        long long fact = 1, sizes = 1;
        for (int i = 2; i <= n; ++i) fact = fact * i % MOD;
        vector<int> st = {0};
        for (int x = 1; x <= n + 1; ++x) {
            while (born[st.back()] > born[x]) {
                st.pop_back();
                sizes = sizes * (x - st.back() - 1) % MOD;
            }
            st.push_back(x);
        }
        return (fact * modPow(sizes, MOD - 2) - 1 + MOD) % MOD;
    }
private:
    static long long modPow(long long b, int e) {
        long long res = 1;
        for (b %= MOD; e; e >>= 1, b = b * b % MOD)
            if (e & 1)  res = res * b % MOD;
        return res;
    }
};