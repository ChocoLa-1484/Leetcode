class Solution {
public:
    int maxDifference(string s) {
        vector<int> count(26);
        int maxO = -1, minE = 105;
        for (auto i : s) {
            count[i - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0)  continue;
            if (count[i] % 2) {
                maxO = max(maxO, count[i]);
            } else {
                minE = min(minE, count[i]);
            }
        }
        return maxO - minE;
    }
};