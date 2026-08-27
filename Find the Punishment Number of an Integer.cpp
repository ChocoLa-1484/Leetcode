int PRE_SUM[1001];

int init = []() {
    for (int i = 1; i <= 1000; i++) {
        auto dfs = [&](this auto&& dfs, int val, int sum) {
            if (val == 0)
                return sum == i;
            for (int x = 0, pow10 = 1; val > 0; val /= 10, pow10 *= 10) {
                x += val % 10 * pow10;
                if (dfs(val / 10, sum + x))
                    return true;
            }
            return false;
        };
        PRE_SUM[i] = PRE_SUM[i - 1] + (dfs(i * i, 0) ? i * i : 0);
    }
    return 0;
}();
class Solution {
public:
    int punishmentNumber(int n) {
        return PRE_SUM[n];
    }
};