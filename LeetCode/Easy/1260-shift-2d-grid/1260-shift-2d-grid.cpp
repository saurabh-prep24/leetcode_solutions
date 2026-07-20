class Solution {
public:
    void rotateRight(vector<int>& arr, int k) {
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> copy;
        int n = grid.size(), m = grid[0].size();
        k = k % (n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                copy.push_back(grid[i][j]);
            }
        }

        rotateRight(copy, k);
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = copy[t++];
            }
        }
        return grid;
    }
};