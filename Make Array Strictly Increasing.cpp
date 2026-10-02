class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr1.push_back(INT_MAX);
        ranges::sort(arr2);
        arr2.erase(ranges::unique(arr2).begin(), arr2.end());
        int n = arr1.size(), f[n];
        for (int i = 0; i < n; i++) {
            int k = ranges::lower_bound(arr2, arr1[i]) - arr2.begin();
            int res = k < i ? INT_MIN : 0; // 小于 a[i] 的?全部替?
            if (i && arr1[i - 1] < arr1[i]) // ?替?
                res = max(res, f[i - 1]);
            for (int j = i - 2; j >= i - k - 1 && j >= 0; --j)
                if (arr2[k - (i - j - 1)] > arr1[j])
                    // a[j+1] 到 a[i-1] 替?成 b[k-(i-j-1)] 到 b[k-1]
                    res = max(res, f[j]);
            f[i] = res + 1; // 把 +1 移到?里，表示 a[i] 不替?
        }
        return f[n - 1] < 0 ? -1 : n - f[n - 1];
    }
};