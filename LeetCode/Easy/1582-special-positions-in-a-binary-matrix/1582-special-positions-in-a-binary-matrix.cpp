class Solution {
public:
    bool check(int r, int c, int n, int m, vector<vector<int>>& mat) {
        for (int i = r - 1; i >= 0; i--) {
            if (mat[i][c] != 0) {
                return 0;
            }
        }
        for (int i = r + 1; i < n; i++) {
            if (mat[i][c] != 0) {
                return 0;
            }
        }

        for (int i = c - 1; i >= 0; i--) {
            if (mat[r][i] != 0) {
                return 0;
            }
        }
        for (int i = c + 1; i < m; i++) {
            if (mat[r][i] != 0) {
                return 0;
            }
        }
        return mat[r][c] == 1;
    }
    // time: O(n * m * (n + m))
    // space: O(1)
    int brute(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && check(i, j, n, m, mat)) {
                    ans++;
                }
            }
        }
        return ans;
    }

    // time: O(n * m)
    // space: O(n+m)
    int opt(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCount1(n, 0);
        vector<int> colCount1(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    rowCount1[i]++;
                    colCount1[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 && rowCount1[i] == 1 && colCount1[j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }

    int numSpecial(vector<vector<int>>& mat) {
        // return brute(mat);

        return opt(mat);
    }
};