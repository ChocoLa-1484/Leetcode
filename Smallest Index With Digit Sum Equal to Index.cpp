class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (const auto& [i, x] : nums | views::enumerate) {
            int sum = 0;
            while (x != 0) {
                sum += x % 10;
                x /= 10;
            }
            if (sum == i)   return i;
        }
        return -1;
    }
};