class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        int tmp = x;
        long res = 0;
        while (tmp != 0) {
            res = res * 10 + tmp % 10;
            tmp /= 10;
        }
        if (x == res)   return true;
        return false;
    }
};