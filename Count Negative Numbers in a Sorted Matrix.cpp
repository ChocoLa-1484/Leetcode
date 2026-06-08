class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int maxR = grid.size();
        int maxC = grid[0].size();
        int row = 0;
        int col = maxC - 1;
        int ans = 0;
        while (row < maxR && col >= 0) {
            if (grid[row][col] >= 0) {
                row++;
            } else {
                ans += maxR - row;
                col--;
            }
        }
        return ans;
    }
};