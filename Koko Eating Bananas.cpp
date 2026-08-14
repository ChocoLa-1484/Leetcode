class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = ranges::max(piles);
        int n = piles.size();
        if (n == h) return r;
        ranges::sort(piles);
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            int sum = n;
            for (const int x : piles) {
                sum += (x - 1) / mid;
                if (sum > h) break;
            }
            if (sum <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};