class Solution {
    const string en[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void dfs(string s, int now, string digits, vector<string>& ans) {
        if (s.length() == digits.length())  {
            if (s != "")    ans.push_back(s);
            return;
        }
        for (int i = 0; i < en[digits[now] - '0'].length(); i++) {
            s += en[digits[now] - '0'][i];
            dfs(s, now + 1, digits, ans);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs("", 0, digits, ans);
        return ans;
    }
};