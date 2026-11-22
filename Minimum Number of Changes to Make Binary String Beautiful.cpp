class Solution {
public:
    int minChanges(string s) {
        return ranges::count_if(views::iota(0, ssize(s) / 2), [&](int i) { return s[i << 1] != s[i << 1 | 1]; });
    }
};