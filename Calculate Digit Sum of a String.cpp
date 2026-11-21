class Solution {
public:
    string digitSum(string s, int k) {
        while (ssize(s) > k) {
            string next;
            for (int i = 0, sum = 0; i < s.length(); i += k) {
                string_view group = string_view(s).substr(i, k);
                for (int j = 0; j < k && i + j < s.length(); ++j) sum += s[i + j] - '0';
                next += to_string(ranges::fold_left(group, 0, [](int sum, char d) { return sum += d - '0'; }));
            }
            s = move(next);
        }
        return s;
    }
};