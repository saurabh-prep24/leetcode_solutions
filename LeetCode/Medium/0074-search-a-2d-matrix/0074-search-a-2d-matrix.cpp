class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int stRow = 0, endRow = matrix.size() - 1;
        int stCol = 0, endCol = matrix[0].size() - 1;

        int start = stRow, end = endRow;
        // find possible row using last elem of each row compared with target
        while (start <= end) {
            int mid = start + (end - start) / 2;

            int curr = matrix[mid][endCol];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }
        if(start > endRow){
            return false;
        }
        int possibleRow = start;
        // check in possibleRow for each cols
        start = stCol, end = endCol;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            int curr = matrix[possibleRow][mid];
            if (curr == target) {
                return true;
            } else if (curr < target) {
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }

        return false;
    }
};