class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> last(n);
        int c = 0;
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            last[i] = c;
            if (j >= 0 && word1[i] == word2[j]) {
                j--, c++;
            }
        }
        vector<int> ans;
        ans.reserve(m);
        bool skip = false;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            bool same = word1[i] == word2[j];
            if (same || (!skip && last[i] >= m - 1 - j)) {
                ans.push_back(i);
                j++;
                skip |= !same;
            }
        }
        return ans.size() == m ? ans : vector<int>{};
    }
};