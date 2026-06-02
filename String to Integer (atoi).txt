class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool positive = true;
        while(s[i] == ' ')  i++;
        if (s[i] == '-') {
            positive = false;
            i++;
        } else if(s[i] == '+') {
            positive = true;
            i++;
        }
        int ans = 0;
        while('0' <= s[i] && s[i] <= '9')   {
            if (ans > INT_MAX / 10) return (positive ? INT_MAX : INT_MIN);
            if (ans == INT_MAX / 10) {
                if (positive && s[i] >= '7') return INT_MAX;
                if (!positive && s[i] >= '8')    return INT_MIN;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        if (!positive)  ans = -ans;
        return ans;
    }
};