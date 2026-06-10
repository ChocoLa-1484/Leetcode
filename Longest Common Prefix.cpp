class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t pre = strs[0].length();
        for(int i = 1; i < strs.size(); i++) {
            pre = min(strs[i].length(), pre);
            for (int j = 0; j < pre; j++) {
                if (strs[0][j] != strs[i][j]) {
                    pre = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, pre);
    }
};