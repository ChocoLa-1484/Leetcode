class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = -1, r = m * n;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);
            int x = matrix[mid / m][mid % m];
            if (x == target)    return true;
            (x >= target ? r : l) = mid;
        }
        return false;
    }
};