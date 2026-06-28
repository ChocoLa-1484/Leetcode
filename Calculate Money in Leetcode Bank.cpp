class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7, day = n % 7;
        return (28 * 2 + (week - 1) * 7) * week / 2 + (1 + week + day + week) * day / 2;
    }
};