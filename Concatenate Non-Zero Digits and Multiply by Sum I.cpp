class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, y = 0;
        for (int i = 1; n != 0; n /= 10) {
            int v = n % 10;
            if (v == 0) continue;
            y += v;
            x += v * i;
            i *= 10;
        }
        return x * 1LL * y;
    }
};