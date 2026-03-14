class Solution {
public:
    int binarySearch(vector<int>& matrix, int target) {
        // search
        int st = 0, end = matrix.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int curr = matrix[mid];
            if (curr == target) {
                return -1;
            } else if (curr < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        // cout<<st<<" "<<end<<endl;
        return st;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        vector<int> down;
        for (int i = 0; i < n; i++) {
            down.push_back(matrix[i][0]);
        }

        int possibleRow = binarySearch(down, target);
        if (possibleRow == -1) {
            return 1;
        }

        cout << possibleRow << endl;

        possibleRow = possibleRow>=n ?  n-1: possibleRow;

        for (int i = possibleRow; i < n && i >= 0; i--) {
            int possibleCol = binarySearch(matrix[i], target);
            cout << possibleCol << endl;
            if (possibleCol == -1) {
                return 1;
            }
        }
        return 0;
    }
};