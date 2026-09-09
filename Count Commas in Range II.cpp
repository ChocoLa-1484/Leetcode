class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if (1000 <= n)  ans += n - 999;
        if (1000000 <= n)   ans += n - 999999;
        if (1000000000 <= n)   ans += n - 999999999;
        if (1000000000000 <= n)   ans += n - 999999999999;
        if (1000000000000000 <= n)   ans += n - 999999999999999;
        return ans;
    }
};