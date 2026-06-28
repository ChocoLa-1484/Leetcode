class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        bitset<100005> bit;
        for (int i = 1; i <= k; i++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return i;
            if (bit[remainder]) return -1;
            bit[remainder] = 1;
        }
        return -1;
    }
};