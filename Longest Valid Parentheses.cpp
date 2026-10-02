class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') 
                st.push(i);
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int l = 0, r = 0, ans = 0;
        for (const char c : s) {
            c == '(' ? l++ : r++;
            if (l == r) ans = max(ans, 2 * l);
            if (l < r)  l = 0, r = 0;
        }
        l = 0, r = 0;
        for (const char c : s | views:: reverse) {
            c == '(' ? l++ : r++;
            if (l == r) ans = max(ans, 2 * l);
            if (r < l)  l = 0, r = 0;
        }
        return ans;
    }
};