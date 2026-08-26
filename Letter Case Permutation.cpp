class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n = s.length();
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(s);
                return;
            }
            dfs(i + 1);
            if (isalpha(s[i])) {
                s[i] ^= 32;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};