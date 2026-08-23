class Solution {
public:
    bool sumGame(string num) {
        int q = 0, sum = 0;
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if (num[i] == '?')
                q += i < n / 2 ? -1 : 1;
            else
                sum += i < n / 2 ? num[i] - '0' : -(num[i] - '0');
        }
        return sum * 2 != q * 9;
    }
};