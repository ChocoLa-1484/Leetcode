class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        constexpr int MOD = 1e9 + 7;
        int n = 0;
        unordered_map<int, int> cnt1, cnt2; 
        cnt2[0] = 1;
        int cur = 0;
        int a, b;
        for (int i : nums) {
            cur ^= i;
            a = cnt2.count(cur ^ target1) ? cnt2[cur ^ target1] : 0;
            b = cnt1.count(cur ^ target2) ? cnt1[cur ^ target2] : 0;
            cnt1[cur] = (cnt1[cur] + a) % MOD;
            cnt2[cur] = (cnt2[cur] + b) % MOD;
        }
        return (a + b) % MOD;
    }
};