class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1.0, xx = x;
        bool min = 0;
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN)   {
                min = 1;
                n++;
            }
            n = -n;
        }
        while (n) {
            if (n & 1)  ret *= x;
            x *= x;
            n >>= 1;
        }
        if (min)    ret *= xx;
        return ret;
    }
};