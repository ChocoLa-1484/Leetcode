class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for (const auto& [id, c] : s | views::enumerate) {
            sum += (id + 1) * (26 - c + 'a');
        }
        return sum;
    }
};