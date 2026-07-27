class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i : nums) {
            b = max(b, min(a, i));
            a = max(a, i);
        }
        return (a - 1) * (b - 1);
    }
};