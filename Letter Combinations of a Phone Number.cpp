class Solution {
    static constexpr string en[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.length();
        string path(n, 0);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (const char c : en[digits[i] - '0']) {
                path[i] = c;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};