class Solution {
public:
    void func(int n1, const string s1, int n2, const string s2, int& num, string& ans) {
        if (num >= n1) {
            ans += s1;
            num -= n1;
        } else {
            int D = num / n2;
            num %= n2;
            while(D--)  ans += s2;
        }
    }
    string intToRoman(int num) {
        string ans = "";
        int D = num / 1000;
        num %= 1000;
        while (D--) ans += 'M';

        func(900, "CM", 500, "D", num, ans);
        func(400, "CD", 100, "C", num, ans);
        func(90, "XC", 50, "L", num, ans);
        func(40, "XL", 10, "X", num, ans);
        func(9, "IX", 5, "V", num, ans);
        func(4, "IV", 1, "I", num, ans);

        return ans;
    }
};