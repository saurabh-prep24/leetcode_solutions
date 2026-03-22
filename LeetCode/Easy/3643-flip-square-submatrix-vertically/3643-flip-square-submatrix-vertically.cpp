class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {

        int n = grid.size(), m = grid[0].size();
        int rowSt = x, colSt = y, rowEnd = x + k - 1, colEnd = y + k - 1;
        while (rowSt < rowEnd) {
            for (int j = colSt; j <= colEnd; j++) {
                swap(grid[rowSt][j], grid[rowEnd][j]);
            }
            rowSt++;
            rowEnd--;
        }
        return grid;
    }
};