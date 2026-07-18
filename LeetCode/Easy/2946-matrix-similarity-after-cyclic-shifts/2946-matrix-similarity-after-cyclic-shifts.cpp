class Solution {
public:
    // rotate right by k places
    void rotateRight(vector<int>& row, int k) {
        int n = row.size();
        // rotate full
        reverse(row.begin(), row.end());
        // rotate parts
        reverse(row.begin(), row.begin() + k);
        reverse(row.begin() + k, row.end());
    }
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        // normalise
        k = k % m;

        // all rows
        for (int i = 0; i < n; i++) {
            vector<int> rev = mat[i];
            if (i & 1) {
                // even so do right rotate by m-k [same as left rotate]
                rotateRight(rev, m - k);
            } else {
                // odd so rotate right by k
                rotateRight(rev, k);
            }
            // check if not equal then return false
            // for (int j = 0; j < m; j++) {
            // cout<<"rev: "<<rev[j]<<" num: "<< mat[i][j]<<"\n";
            // }
            if (rev != mat[i]) {
                return 0;
            }
        }
        return 1;
    }
};