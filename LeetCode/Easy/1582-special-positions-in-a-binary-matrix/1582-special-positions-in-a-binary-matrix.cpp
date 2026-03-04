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
    int numSpecial(vector<vector<int>>& mat) {
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
};