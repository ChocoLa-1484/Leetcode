class Solution {
    inline static int indexOfMax(vector<int>& a) {
        return ranges::max_element(a) - a.begin();
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l = -1, r = mat.size() - 1;
        while (l + 1 < r) {
            int i = l + ((r - l) >> 1);
            int j = indexOfMax(mat[i]);
            (mat[i][j] > mat[i + 1][j] ? r : l) = i;
        }
        return {r, indexOfMax(mat[r])};
    }
};