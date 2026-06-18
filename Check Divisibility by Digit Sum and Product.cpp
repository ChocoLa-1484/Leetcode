class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n, sum = 0, pro = 1;
        while (x != 0) {
            int z = x % 10;
            sum += z, pro *= z;
            x /= 10;
        }
        return !(n % (sum + pro));
    }
};