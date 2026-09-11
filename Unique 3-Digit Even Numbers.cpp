class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (const int x : digits)  cnt[x]++;
        int ans = 0;
        for (int i = 1; i < 10; i++) {
            if (cnt[i] == 0)    continue;
            cnt[i]--;
            for (int j = 0; j < 10; j++) {
                if (cnt[j] == 0)    continue;
                cnt[j]--;
                for (int k = 0; k < 10; k += 2) {
                    if (cnt[k] == 0)    continue;
                    ans++;
                }
                cnt[j]++;
            }
            cnt[i]++;
        }
        return ans;
    }
};