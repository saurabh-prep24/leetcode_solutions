class Solution {
public:
    void print(vector<vector<char>> v) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << "--------------" << endl;
    }

    // better - we can move to # to right side 
    // [similar to move 1 to rights in binary arr]
    // then rot it would be easier
    // but solved like this for complexity
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> rot(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rot[j][n - i - 1] = boxGrid[i][j];
            }
        }
        // print(rot);
        for (int i = 0; i < n; i++) {
            // track non-obstacles index
            int emp = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                // move emp to prev
                if (rot[j][i] == '*') {
                    emp = j - 1;
                } else if (rot[j][i] == '#') {
                    // swap and move emp to prev
                    swap(rot[j][i], rot[emp][i]);
                    emp--;
                }
            }
        }
        // print(rot);
        return rot;
    }
};