class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length(), n = num2.length();
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> ans(n + m, 0);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--) {
               int y = num2[j] - '0';
               ans[i + j + 1] += x * y; 
            }
        }
        string s = "";
        for (int i = n + m - 1; i > 0; i--) {
            ans[i - 1] += ans[i] / 10;
            ans[i] %= 10;
            s += (char)(ans[i] + '0');
        }
        if (ans[0] != 0)    s += (char)(ans[0] + '0');
        reverse(s.begin(), s.end());
        return s;
    }
};