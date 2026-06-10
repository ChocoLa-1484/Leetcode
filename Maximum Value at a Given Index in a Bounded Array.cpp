class Solution {
public:
    long long calc(long long peak, long long cnt) {
        return peak >= cnt ? ((peak - cnt + 1) + peak) * cnt / 2 : (peak + 1) * peak / 2 + (cnt - peak);
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 0, r = maxSum;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            long long sum = calc(mid, index + 1) + calc(mid, n - index) - mid;
            if (sum <= maxSum) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};