class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(n * 2, 0);
        auto dfs = [&](this auto&& dfs, int l, int r) {
            if(r == n) {
                ans.push_back(path);
                return;
            }
            if (l < n) {
                path[l + r] = '(';
                dfs(l + 1, r);
            }
            if (r < l) {
                path[l + r] = ')';
                dfs(l, r + 1);
            }
        };
        dfs(0, 0);
        return ans;
    }
};