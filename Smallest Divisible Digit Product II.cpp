class Solution {
    int getMinDigits(array<int, 4> cnt) {
        for (int& i : cnt)   i = max(0, i);
        int count = cnt[0] / 3 + cnt[1] / 2 + cnt[2] + cnt[3];
        cnt[0] %= 3;    cnt[1] %= 2;
        if (cnt[0] == 2 && cnt[1] == 1) count += 2;
        else if (cnt[0] >= 1 || cnt[1] >= 1)    count++;
        return count;
    }
    string build(array<int, 4> cnt, int len) {
        for (int& i : cnt)   i = max(0, i); 
        array<int, 10> a = {};
        a[5] = cnt[2];  a[7] = cnt[3];  a[8] = cnt[0] / 3;  a[9] = cnt[1] / 2;
        cnt[0] %= 3;    cnt[1] %= 2;
        if (cnt[0] >= 1 && cnt[1] >= 1) a[6]++, cnt[0]--, cnt[1]--;
        if (cnt[0] >= 2)    a[4]++, cnt[0] -= 2;
        a[2] += cnt[0]; a[3] += cnt[1];
        int count = 0;
        for (int i = 2; i < 10; i++)    count += a[i];
        a[1] = len - count;
        string ret = "";    ret.reserve(len);
        for (int i = 1; i < 10; i++)
            ret.append(a[i], i + '0');
        return ret;
    }
public:
    string smallestNumber(string num, long long t) {
        constexpr int prime[4] = {2, 3, 5, 7};
        auto factorize = [&](long long& t) {
            array<int, 4> cnt = {};
            for (int i = 0; i < 4; i++) {
                while (t % prime[i] == 0) {
                    cnt[i]++;
                    t /= prime[i];
                }
            }
            return cnt;
        };
        array<int, 4> cnt = factorize(t);
        if (t != 1) return "-1";
        int n = num.length();
        vector<vector<int>> pref(4, vector<int>(n + 1));
        int maxI = n;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (d == 0) {
                maxI = i;break;
            }
            long long td = d;
            auto fac = factorize(td);
            for (int j = 0; j < 4; j++)
                pref[j][i + 1] = pref[j][i] + fac[j];
        }
        array<int, 4> rem;
        for (int i = 0; i < 4; i++) rem[i] = cnt[i] - pref[i][maxI];
        if (maxI == n && getMinDigits(rem) == 0)   return num;
        for (int i = maxI; i >= 0; i--) {
            int st = (i < n) ? num[i] - '0' + 1 : 1;
            for (int d = st; d <= 9; d++) {
                long long td = d;
                auto fac = factorize(td);
                for (int j = 0; j < 4; j++)
                    fac[j] = cnt[j] - pref[j][i] - fac[j];
                int len = n - i - 1;
                if (getMinDigits(fac) <= len)
                    return num.substr(0, i) + to_string(d) + build(fac, len);
            }
        }
        return build(cnt, max(n + 1, getMinDigits(cnt)));
    }
};


class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        for (int i = 2; i <= 9; i++) {
            while (temp % i == 0)
                temp /= i;
        }
        if (temp > 1)   return "-1";
        int n = num.length();
        vector<long long> rem(n + 1);
        rem[0] = t;
        int maxI = n - 1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                maxI = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }
        if (rem[n] == 1)    return num;
        for (int i = maxI; i >= 0; i--) {
            while (++num[i] <= '9') {
                long long tNow = rem[i] / gcd(rem[i], num[i] - '0');
                int k = 9;
                for (int j = n - 1; j > i; j--) {
                    while (tNow % k)    k--;
                    tNow /= k;
                    num[j] = '0' + k;
                }
                if (tNow == 1)
                    return num;
            }
        }
        string ans = "";
        for (int i = 9; i > 1; i--) {
            while (t % i == 0) {
                ans += '0' + i;
                t /= i;
            }
        }
        ans += string(max(n + 1 - (int)ans.length(), 0), '1');
        ranges::reverse(ans);
        return ans;
    }
};