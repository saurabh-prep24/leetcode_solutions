class Solution {
public:
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] != target[i][j]) {
                    return 0;
                }
            }
        }
        return 1;
    }
    void print(vector<vector<int>>& mat) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> rotated = mat;
        int n = mat.size();
        int m = mat[0].size();
        // check if both are same initially then return
        if (check(mat, target)) {
            return 1;
        }
        // check upto 3 rotations [4 one will be input mat]
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // each rot gets
                    // mat[i][j] = rot[j][m-i-1]
                    // so assign it acc.
                    rotated[j][m - i - 1] = mat[i][j];
                }
            }
            // print(rotated);
            // check if equal then return
            if (check(rotated, target)) {
                return 1;
            }
            // change mat to rotate for next rotation
            mat = rotated;
        }
        // no match found
        return 0;
    }
};