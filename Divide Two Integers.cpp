class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)    return 1;
        if (dividend == INT_MIN && divisor == -1)   return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)   return INT_MIN; 
        bool neg = (dividend ^ divisor) < 0;
        unsigned int a = dividend == INT_MIN ? dividend : abs(dividend);
        unsigned int b = divisor == INT_MIN ? divisor : abs(divisor);
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if ((a >> i) < b)   continue;
            ans += (1 << i);
            a -= (b << i);
        }
        return neg ? -ans : ans;
    }
};