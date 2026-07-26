class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX;
        for (int i : nums) {
            if (i > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = i;
            } else if (i > mx2) {
                mx3 = mx2;
                mx2 = i;
            } else if (i > mx3) {
                mx3 = i;
            }
            if (i < mn1) {
                mn2 = mn1;
                mn1 = i;
            } else if (i < mn2) {
                mn2 = i;
            }
        }
        return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
    }
};