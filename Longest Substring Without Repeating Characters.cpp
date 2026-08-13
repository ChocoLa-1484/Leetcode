class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bitset<128> bs;
        int n = s.length();
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            while (bs.test(s[r]))
                bs.reset(s[l++]);
            bs.set(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};