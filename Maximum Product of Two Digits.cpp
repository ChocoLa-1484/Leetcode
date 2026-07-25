class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0, mx2 = 9;
        while (n != 0) {
            int x = n % 10;
            if (x > mx1) {
                mx2 = mx1;
                mx1 = n % 10;
            } else if (x > mx2) {
                mx2 = x;
            }
            n /= 10; 
        }
        return mx1 * mx2;
    }
};