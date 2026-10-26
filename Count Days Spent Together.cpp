class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        static constexpr int pre[] = {
            0, 0, 31, 59, 90, 120, 151,
            181, 212, 243, 273, 304, 334
        };
        auto toDay = [&](const string& s) {
            int m = (s[0] - '0') * 10 + s[1] - '0';
            int d = (s[3] - '0') * 10 + s[4] - '0';
            return pre[m] + d;
        };
        return max(0, toDay(min(leaveAlice, leaveBob)) - toDay(max(arriveAlice, arriveBob)) + 1);
    }
};