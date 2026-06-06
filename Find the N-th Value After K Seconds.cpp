class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9 + 7;
        int triangle[n + k][n + k];
        for (int i = 0; i < n + k; i++) {
            triangle[i][i] = triangle[i][0] = 1;
            for (int j = 1; j < i; j++) {
                triangle[i][j] = ((long long)triangle[i - 1][j - 1] + triangle[i - 1][j]) % mod;
            }
        }
        return triangle[n + k - 1][k];
    }
};

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        int mod = 1e9 + 7;
        vector <int> pre(n);
        fill(pre.begin(), pre.end(), 1);
        while (k--) {
            for (int i = 1; i < n; i++) {
                pre[i] = (pre[i] + pre[i - 1]) % mod;
            }
        }
        return pre[n - 1];
    }
};
