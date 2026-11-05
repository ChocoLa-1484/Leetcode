class Solution {
public:
    static constexpr long long INF = 1LL << 60;
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
        };

        auto remove = [&](int v) {
            if (auto it = left.find(v); it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                right.erase(right.find(v));
                sumR -= v;
            }
        };

        auto balance = [&]() {
            int target = (x + 1) / 2;

            while (left.size() > target) {
                int v = *left.rbegin();
                left.erase(prev(left.end()));
                sumL -= v;

                right.insert(v);
                sumR += v;
            }

            while (left.size() < target) {
                int v = *right.begin();
                right.erase(right.begin());
                sumR -= v;

                left.insert(v);
                sumL += v;
            }
        };

        auto getCost = [&]() -> long long {
            long long mid = *left.rbegin();
            return mid * left.size() - sumL + sumR - mid * right.size();
        };

        for (int i = 0; i < x; ++i) add(nums[i]);
        balance();
        vector<long long> cost(n - x + 1);
        cost[0] = getCost();
        for (int i = x; i < n; ++i) {
            add(nums[i]);
            remove(nums[i - x]);
            balance();
            cost[i - x + 1] = getCost();
        }
        vector<long long> dp(n + 1, 0);
        for (int j = 1; j <= k; ++j) {
            vector<long long> ndp(n + 1, INF);
            for (int i = j * x; i <= n; ++i) 
                ndp[i] = min(ndp[i - 1], dp[i - x] + cost[i - x]);
            dp = move(ndp);
        }
        return dp.back();
    }
};