class Solution {
public:
    bool binarySearchRowAndColwise(vector<vector<int>>& matrix, int target){
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

    // n * m matrix convert to an array => matrix[x][y] => a[x * m + y]
    // an array convert to n * m matrix => a[x] => matrix[x / m][x % m];
    bool binarySearchCompleteArr(vector<vector<int>>& matrix, int target){
        // since arr is sorted row and col wise then we can consider
        // this as single arr with m*n elem then apply binary search
        // calc mid 
        // then curr elem will be matrix[mid/cols][mid%cols]
        // ex- m[4,4] - 4x4
        // mid = [16/2] = 8
        // row = 8/4 = 2 | col = 8%4 = 0
        // so 8th index elem represent m[2][0] [row 0 & 1 has 4 elems]
        // ---
        // Mapping 1D Index → 2D Index
        // For a matrix with cols = n
        // - row = index / n
        // - col = index % n
        // This works because:
        // - index = row * n + col
        int n = matrix.size(), m = matrix[0].size();
        int st = 0, end = n*m-1;
        while(st<=end){
            int mid = st + (end-st)/2;

            int curr = matrix[mid/m][mid%m];
            if(curr == target){
                return true;
            }else if(curr<target){
                st = mid +1;
            }else{
                end = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // return binarySearchRowAndColwise(matrix, target);
        return binarySearchCompleteArr(matrix, target);
    }
};