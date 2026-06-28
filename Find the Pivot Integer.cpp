class Solution {
public:
    int pivotInteger(int n) {
        for (int i = 1; i <= n; i++) {
            int x = (1 + i) * i / 2;
            int y = (i + n) * (n - i + 1) / 2;
            if (x == y) return i;
        }
        return -1;
    }
};