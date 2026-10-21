class Solution {
public:
    int minOperations(string s) {
        if (ranges::is_sorted(s))  return 0;
        const int n = s.length();
        if (n == 2)    return -1;
        auto [mn, mx] = minmax_element(s.begin() + 1, s.end() - 1);
        if (s[0] <= min(*mn, s.back()) || s.back() >= max(*mx, s[0])) return 1;
        return s.back() < *mn && s[0] > *mx ? 3 : 2;
    }
};