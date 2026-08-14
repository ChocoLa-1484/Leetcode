class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        ranges::sort(price);
        auto check = [&](int gap) {
            int pre = price[0], t = 1;
            for (int i = 1; i < n; i++) {
                if (price[i] - pre >= gap) {
                    pre = price[i];
                    t++;
                }
                if (t == k) return true;
            }
            return false;
        };
        int l = 0, r = (price.back() - price[0]) / (k - 1) + 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            (check(mid) ? l : r) = mid;
        }
        return l;
    }
};