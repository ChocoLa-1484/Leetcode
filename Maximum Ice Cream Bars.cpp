#define M (int)(1e5+1)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt[M] = {};
        for (auto i : costs) 
            cnt[i]++;
        int res = 0;
        for (int i = 1; i < M; i++) {
            if (cnt[i] == 0)    continue;
            if (coins >= i) {
                int num = min(cnt[i], coins / i);
                res += num;
                coins -= num * i;
            } else {
                break;
            }
        }
        return res;
    }
};