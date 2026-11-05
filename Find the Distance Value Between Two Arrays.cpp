class Solution {
public:
    static constexpr int offset = 1000;
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        bitset<2001> b, mask;
        for (int x : arr2) b.set(x + offset);
        for (int i = 0; i <= d; ++i) mask |= (b << i) | (b >> i);
        return ranges::count_if(arr1, [&](int x) {
            return !mask.test(x + offset);
        });
    }
};

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr2);
        int ans = 0;
        for (const int x : arr1) {
            auto it = ranges::lower_bound(arr2, x - d);
            if (it != arr2.end() && *it <= x + d)  continue;
            ans++;
        }
        return ans;
    }
};