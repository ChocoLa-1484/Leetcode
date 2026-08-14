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