class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int v[10001] = {};
        for (const int x : nums)    v[x] += x;
        int f0 = 0, f1 = 0;
        for (const int x : v) {
            f0 = exchange(f1, max(f1, f0 + x));
        }
        return f1;
    }
};