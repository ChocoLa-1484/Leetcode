class Solution {
public:
    void r(int i, int j, int n, vector<vector<int>>& matrix) {
        swap(matrix[i][j], matrix[j][n - 1 - i]);
        swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
        swap(matrix[i][j], matrix[n - 1 - j][i]);
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n >> 1); i++) {
            for (int j = i; j < n - i - 1; j++)
                r(i, j, n, matrix);
        }
    }
};