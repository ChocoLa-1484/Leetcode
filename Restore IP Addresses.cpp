class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.length();
        if (n < 4 || n > 12)    return {};
        vector<int> dots;
        auto dfs = [&](this auto&& dfs, int i) {
            if (dots.size() == 4) {
                if (i == n) {
                    string tmp = "";
                    for (int j = 0, l = 0; j < n; j++) {
                        tmp += s[j];
                        if (dots[l] == j && l != 3) {
                            tmp += ".";
                            l++;
                        }
                    }
                    ans.emplace_back(tmp);
                }
                return;
            }
            if (s[i] == '0') {
                dots.push_back(i);
                dfs(i + 1);
                dots.pop_back();
                return;
            }
            string tmp = "";
            for (int j = 0; j < 3 && i + j < n; j++) {
                tmp += s[i + j];
                if (0 <= stoi(tmp) && stoi(tmp) <= 255) {
                    dots.push_back(i + j);
                    dfs(i + j + 1);
                    dots.pop_back();
                }
            }  
        };
        dfs(0);
        return ans;
    }
};