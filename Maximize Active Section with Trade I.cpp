class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int sum = count(s.begin(), s.end(), '1');
        int i = 0, mx = 0, prev = INT_MIN, cur = 0;
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start])   ++i;
            if (s[start] == '0') {
                cur = i - start;
                mx = max(mx, prev + cur);
                prev = cur;
            }
        }
        return sum + mx;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();