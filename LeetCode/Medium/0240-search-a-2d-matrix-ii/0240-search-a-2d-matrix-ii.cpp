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

    // find upper bound of target then loop on 
    // time: O(nlog(m+n))
    int searchBinary(vector<vector<int>>& matrix, int target){
        int n = matrix.size(), m = matrix[0].size();

        vector<int> down;
        for (int i = 0; i < n; i++) {
            down.push_back(matrix[i][0]);
        }

        int possibleRow = binarySearch(down, target);
        if (possibleRow == -1) {
            return 1;
        }

        possibleRow = possibleRow >= n ? n - 1 : possibleRow;

        for (int i = possibleRow; i < n && i >= 0; i--) {
            // if last is smaller than target then we can skip all prev rows
            if(matrix[i][m-1] <target){
                break;
            }
            int possibleCol = binarySearch(matrix[i], target);
            // cout << possibleCol << endl;
            if (possibleCol == -1) {
                return 1;
            }
        }
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // brute force
        // check all elem - O(N*M)

        // time: O(N*log(m+n))
        return searchBinary(matrix, target);
    }
};