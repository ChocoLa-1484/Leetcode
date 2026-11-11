class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mx = max(need1, need2), mn = min(need1, need2);
        long long t = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long s = costBoth * mn + cost1 * (need1 - mn) + cost2 * (need2 - mn);
        return min(costBoth * mx, min(t, s));
    }
};