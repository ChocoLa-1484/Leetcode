class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string ss = "";
        int i = 0;
        for (i = 0; i + k < s.length(); i += k) {
            ss = s.substr(i, k);
            ans.push_back(ss);
        }
        if (i != s.length()) {
            ss = s.substr(i, k);
        }
        while (ss.length() != k) {
            ss += fill;
        }
        ans.push_back(ss);
        return ans;
    }
};