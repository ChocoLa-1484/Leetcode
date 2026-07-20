class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                string s1 = s.substr(0, i);
                string ss = "";
                for (int j = 0; j < n / i; j++)
                    ss += s1;
                if (ss == s) return true;
            }
        }
        return false;
    }
};