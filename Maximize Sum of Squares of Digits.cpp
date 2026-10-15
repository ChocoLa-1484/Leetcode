class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)  return "";
        string ans;
        ans.reserve(num);
        const int cnt = sum / 9, remainder = sum % 9;
        ans.append(cnt, '9');
        if (ans.length() < num) {
            ans += remainder + '0';
            ans.append(num - ans.length(), '0');
        }
        return ans;
    }
};