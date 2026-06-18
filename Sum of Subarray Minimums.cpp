class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> stack;
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[stack.back()] >= arr[i])
                stack.pop_back();
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);
        }
        vector<int> right(n, n);
        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.empty() && arr[stack.back()] > arr[i])
                stack.pop_back();
            right[i] = stack.empty() ? n : stack.back();
            stack.push_back(i);
        }
        long long ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long l = i - left[i], r = right[i] - i;
            ans = (ans + l * r * arr[i]) % MOD;
        }
        return ans;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> stack;
        long long ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i <= n; i++) {
            while (!stack.empty() && (i == n || arr[stack.back()] >= arr[i])) {
                int pivot = stack.back();
                stack.pop_back();
                int left = stack.empty() ? -1 : stack.back(), right = i;
                long long l = pivot - left, r = right - pivot;
                ans = (ans + l * r % MOD * arr[pivot]) % MOD;
            }
            stack.push_back(i);
        }
        return ans;
    }
};