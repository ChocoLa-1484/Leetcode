class Solution {
public:
    int smallestNumber(int n, int t) {
        while (1) {
            int x = n, sum = 1;
            while (x != 0) {
                sum *= x % 10;
                x /= 10;
            }
            if (sum % t == 0)
                return n;
            n++;
        }
        return n;
    }
};