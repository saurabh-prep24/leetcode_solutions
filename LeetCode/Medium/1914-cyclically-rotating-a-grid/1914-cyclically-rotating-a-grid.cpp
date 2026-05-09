class Solution {
public:
    void rotateLeftByK(vector<int>& v, int k) {
        k = k % v.size();
        if (k == 0 || v.size() <= 1)
            return;

        reverse(v.begin(), v.begin() + k);
        reverse(v.begin() + k, v.end());
        reverse(v.begin(), v.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        // total layers are min of (rows, cols)
        int maxLayers = min(n / 2, m / 2);
        for (int layer = 0; layer < maxLayers; layer++) {
            // convert to 1D arr
            int stRow = layer, endRow = n - 1 - layer;
            int stCol = layer, endCol = m - 1 - layer;
            vector<int> temp;
            for (int i = stCol; i <= endCol; i++) {
                temp.push_back(grid[stRow][i]);
            }
            for (int i = stRow + 1; i <= endRow; i++) {
                temp.push_back(grid[i][endCol]);
            }
            for (int i = endCol - 1; i >= stCol; i--) {
                temp.push_back(grid[endRow][i]);
            }
            for (int i = endRow - 1; i > stRow; i--) {
                temp.push_back(grid[i][stCol]);
            }

            // rot by k
            rotateLeftByK(temp, k);

            // re-assign back
            int curr = 0;
            for (int i = stCol; i <= endCol; i++) {
                grid[stRow][i] = temp[curr++];
            }
            for (int i = stRow + 1; i <= endRow; i++) {
                grid[i][endCol] = temp[curr++];
            }
            for (int i = endCol - 1; i >= stCol; i--) {
                grid[endRow][i] = temp[curr++];
            }
            for (int i = endRow - 1; i > stRow; i--) {
                grid[i][stCol] = temp[curr++];
            }
        }
        return grid;
    }
};