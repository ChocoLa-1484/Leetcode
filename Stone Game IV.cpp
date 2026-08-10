class Solution {
public:
    static constexpr int MAXN = 100000;
    inline static bitset<MAXN + 1> dp;
    inline static const bool init = []() {
        for (int i = 0; i <= MAXN; ++i) {
            if (dp.test(i)) continue;
            for (long long j = 1; i + j * j <= MAXN; ++j)
                dp.set(i + j * j);
        }
        return false;
    }();
    inline bool winnerSquareGame(int n) {
        return dp.test(n);
    }
};