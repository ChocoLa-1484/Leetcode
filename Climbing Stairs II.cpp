class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int f0 = 0, f1 = 0, f2 = 0;
        for (const int x : costs) {
            f0 = exchange(f1, exchange(f2, x + min({f0 + 9, f1 + 4, f2 + 1})));
        }
        return f2;
    }
};