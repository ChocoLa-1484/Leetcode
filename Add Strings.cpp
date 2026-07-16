class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length() - 1, m = num2.length() - 1;
        string ans = "";
        int x = 0;
        while (n >= 0 || m >= 0 || x) {
            int c1 = (n >= 0 ? num1[n] - '0' : 0);
            int c2 = (m >= 0 ? num2[m] - '0': 0);
            int c = c1 + c2 + x;
            ans += c % 10 + '0';
            x = c / 10;
            n--, m--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};