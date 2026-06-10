class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = 0;
        for (int i = 1; i < s.length(); i++) {
            int pre = mp[s[i - 1]], now = mp[s[i]];
            ans = pre >= now ? ans + pre : ans - pre;
        }
        return ans + mp[s.back()];
    }
};