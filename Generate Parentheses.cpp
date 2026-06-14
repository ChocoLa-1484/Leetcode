class Solution {
public:
    void dfs(int n, int l, int r, string s, vector<string>& ans) {
        if(r == n) {
            ans.push_back(s);
            return;
        }
        if (l < n)  dfs(n, l + 1, r, s + '(', ans);
        if (r < l)  dfs(n, l, r + 1, s + ')', ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n, 0, 0, "", ans);
        return ans;
    }
};