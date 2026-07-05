class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n)    return mat;
        vector<vector<int>> ret(r, vector<int>(c)) ;
        int k = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ret[i][j] = mat[k / n][k % n];
                k++;
            }
        }
        return ret;
    }
};