class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0, n = arr.size();
        vector<int> v;
        v.reserve(n);
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                if (v.empty() || v.back() <= arr[j])    v.push_back(arr[j]);
                else    *ranges::upper_bound(v, arr[j]) = arr[j];
            }
            ans += v.size();
            v.clear();
        }
        return n - ans;
    }
};