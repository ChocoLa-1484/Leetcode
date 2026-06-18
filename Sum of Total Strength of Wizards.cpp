class Solution {
public:
    int totalStrength(vector<int>& strength) {
        long long MOD = 1e9 + 7;
        int n = strength.size();
        vector<long long> prefix(n + 1, 0L);
        partial_sum(strength.begin(), strength.end(), prefix.begin() + 1,
                    [&](int a, int b) { return (a + b) % MOD; });
        vector<long long> presum(n + 2, 0L);
        partial_sum(prefix.begin(), prefix.end(), presum.begin() + 1,
                    [&](int a, int b) { return (a + b) % MOD; });
        vector<int> left(n, -1);
        vector<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && strength[stack.back()] >= strength[i])
                stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }
        vector<int> right(n, n);
        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && strength[stack.back()] > strength[i])
                stack.pop_back();
            right[i] = stack.empty() ? n : stack.back();
            stack.push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long pos = (presum[right[i] + 1] - presum[i + 1] + MOD) % MOD *
                            (i - left[i]) % MOD;
            long long neg = (presum[i + 1] - presum[left[i] + 1] + MOD) % MOD *
                            (right[i] - i) % MOD;
            long long contrib = (pos - neg + MOD) % MOD * strength[i] % MOD;
            ans = (ans + contrib) % MOD;
        }
        return ans;
    }
};