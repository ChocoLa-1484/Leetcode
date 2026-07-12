class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)   return n;
        int x1 = 1, x2 = 2;
        for (int i = 3; i <= n; i++) {
            int x3 = x1 + x2;
            x1 = x2;
            x2 = x3;
        }
        return x2;
    }
};