class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 && j >= 0) {
            int x = a[i] - '0', y = b[j] - '0';
            int z = x + y + carry;
            carry = (z >> 1);
            z %= 2;
            ans += (z == 1 ? '1' : '0');
            i--;
            j--;
        }
        while (i >= 0) {
            int x = a[i] - '0';
            int z = x + carry;
            carry = (z >> 1);
            z %= 2;
            ans += (z == 1 ? '1' : '0');
            i--;
        }
        while (j >= 0) {
            int y = b[j] - '0';
            int z = y + carry;
            carry = (z >> 1);
            z %= 2;
            ans += (z == 1 ? '1' : '0');
            j--;
        }
        if (carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};