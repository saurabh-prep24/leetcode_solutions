class Solution {
public:
    /*
        *** method for rotation - in-place rotation [no space required]
        1. get transpose of mat
        [147]
        [258]
        [369]
        2. reverse each col elem for each rows
        [741]
        [852]
        [963]
    */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // transpose of mat
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // swap only lower half
                if (i < j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse col elem for each rows
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};