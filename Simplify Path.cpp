class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        string tmp = "";
        for (int i = 1; i <= n; i++) {
            if (i == n || path[i] == '/') {
                if (tmp == "..") {
                    if (!st.empty())    st.pop();
                } else if (tmp != "" && tmp != ".") {
                    st.push(tmp);
                }
                tmp = "";
                continue;
            }
            tmp += path[i];
        }
        string ans = "/";
        stack <string> st2;
        while (!st.empty()) {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty()) {
            ans += st2.top() + "/";
            st2.pop();
        }
        if (ans.length() != 1)
            ans.pop_back();
        return ans;
    }
};