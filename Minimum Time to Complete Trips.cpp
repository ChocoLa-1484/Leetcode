class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if (time.size() == 1)   return 1LL * time[0] * totalTrips;
        auto check = [&](long long t) {
            long long ret = 0;
            for (const int x : time) {
                ret += t / x;
                if (ret >= totalTrips)   return true;
            }
            return false;
        };
        long long l = 0, r = 1LL * ranges::min(time) * totalTrips;
        while (l + 1 < r) {
            long long mid = l + ((r - l) >> 1);
            (check(mid) ? r : l) = mid;
        }
        return r;
    }
};