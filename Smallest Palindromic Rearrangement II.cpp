class Solution {
public:
    static constexpr long long INF = 1e18;
    long long count(const vector<int>& cnt, int n, int k) {
        long long res = 1;
        for (int i = 0; i < 26; i++) {
            if (!cnt[i])   continue;
            int t = cnt[i];
            for (int j = 1; j <= t; j++) {
                res = res * (n - t + j) / j;
                if (res > k)    return INF;
            }
            n -= t;
        }
        return res;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.length() >> 1;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        if (count(cnt, n, k) < k)    return "";
        string a = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (!cnt[j]) continue;
                cnt[j]--;
                long long p = count(cnt, n - 1 - i, k);
                if (k <= p) {
                    a.append(1, 'a' + j);
                    break;
                } else {
                    k -= p;
                    cnt[j]++;
                }
            }
        }
        string mid = s.length() & 1 ? string(1, s[s.length() >> 1]) : "";  
        return a + mid + string(a.rbegin(), a.rend());
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();