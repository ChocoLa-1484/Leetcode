class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m = minutes * 6.0, h = (hour % 12) * 30.0 + minutes * 30 / 60.0;
        double ans = abs(m - h);
        return min(ans, 360.0 - ans);
    }
};