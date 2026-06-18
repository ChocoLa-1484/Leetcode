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
        long long ans = 0;
        vector<int> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || strength[st.back()] >= strength[i])) {
                int pivot = st.back();  st.pop_back();
                int l = st.empty() ? -1 : st.back(), r = i;
                int ln = pivot - l, rn = r - pivot;
                long long pos = (presum[r + 1] - presum[pivot + 1] + MOD) * ln % MOD;
                long long neg = (presum[pivot + 1] - presum[l + 1] + MOD) * rn % MOD;
                long long contrib = (pos - neg + MOD) * strength[pivot] % MOD;
                ans = (ans + contrib) % MOD;
            }
            st.push_back(i);
        }
        return ans;
    }
};