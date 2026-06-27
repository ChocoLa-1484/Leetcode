class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int mp[31623] = {};
        bitset<31623> seen;
        int maxN = 0;
        for (int x : nums) {
            if (x >= 31623) {
                int rx = sqrt(x);
                if (rx * rx == x)   seen[rx] = 1;
            } else {
                mp[x]++;
                maxN = max(maxN, x);
            }
        }
        int ans = max(mp[1], 1);
        for (int i = 2; i <= maxN; i++) {
            if (ans == 9)   return ans;
            int x = i, tmp = 0;
            while (mp[x]) {
                if (mp[x] >= 2) {
                    tmp += 2;
                } else if (mp[x] == 1) {
                    tmp += 1;
                    break;
                }
                if (x * x >= 31623) break;
                x *= x;
            }
            tmp += seen[x];
            ans = max(ans, tmp);
        }
        return ans & 1 ? ans : ans - 1;
    }
};