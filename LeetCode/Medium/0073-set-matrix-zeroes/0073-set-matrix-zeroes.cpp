class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroElem;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // cout << i << j << endl;
                    zeroElem.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < zeroElem.size(); i++) {
            int x = zeroElem[i].first;
            int y = zeroElem[i].second;
            // cout << x << y << endl;
            int l = y;
            while (l >= 0) {
                matrix[x][l] = 0;
                l--;
            }
            int r = y;
            while (r < m) {
                matrix[x][r] = 0;
                r++;
            }

            int u = x;
            while (u >= 0) {
                matrix[u][y] = 0;
                u--;
            }

            int d = x;
            while (d < n) {
                matrix[d][y] = 0;
                d++;
            }
        }
    }
};