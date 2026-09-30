class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans(n);
        for (int i = 0, l = 0; i < n; i++)
            ans[i] = seq[i] == '(' ? (++l & 1) : (l-- & 1);
        return ans;
    }
};